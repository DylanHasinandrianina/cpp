#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseToken(const std::string& token){

    if (token.empty())
        return false;
    
    size_t i = 0;
    if (token[0] == '-' || token[0] == '+'){
        if (token.length() == 1)
            return false;
        else
            i++;
    }

    for (; i < token.length(); i++){
        if (!std::isdigit(token[i]))
            return false;
    }

    long nbr = std::atol(token.c_str());
    if (nbr < 0)
            return false;
    if (nbr > std::numeric_limits<int>::max())
            return false;

    return true;
}

std::vector<int>::iterator PmergeMe::binarySearchVector(std::vector<int>& v, int value) {
    size_t left = 0;
    size_t right = v.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (v[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return v.begin() + left;
}

std::deque<int>::iterator PmergeMe::binarySearchDeque(std::deque<int>& d, int value) {
    size_t left = 0;
    size_t right = d.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (d[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return d.begin() + left;
}

std::vector<size_t> PmergeMe::jacobsthal_indices(size_t n){
    std::vector<size_t> jacs;
    size_t j0 = 0;
    size_t j1 = 1;
    while (j1 < n){
        jacs.push_back(j1);
        size_t next = j1 + (2 * j0);
        j0 = j1;
        j1 = next;
    }
    return jacs;
}

std::vector<size_t> PmergeMe::build_insertion_order(size_t n)
{
    std::vector<size_t> order;

    std::vector<size_t> jac = jacobsthal_indices(n);

    size_t prev = 0;

    for (size_t i = 0; i < jac.size(); i++)
    {
        size_t j = jac[i];

        for (size_t k = j; k > prev; --k)
            order.push_back(k - 1);

        prev = j;
    }

    for (size_t k = n; k > prev; --k)
        order.push_back(k - 1);

    return order;
}

std::vector<int> PmergeMe::fordVector(std::vector<int>& input) {
    if (input.size() <= 1)
        return input;

    std::vector<std::pair<int,int> > pairs;
    std::vector<int> small, big;
    int straggler = -1;
    if (input.size() % 2 != 0){
        straggler = input.back();
        input.pop_back();
    }

    // create pairs
    for (size_t i = 0; i + 1 < input.size(); i += 2)
        pairs.push_back(std::make_pair(input[i], input[i+1]));

    // sort each pairs
    for (size_t i = 0; i < pairs.size(); i++)
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);

    // divide pairs into small and big
    for (size_t i = 0; i < pairs.size(); i++) {
        small.push_back(pairs[i].first);
        big.push_back(pairs[i].second);
    }

    // sort big
    if (!big.empty())
        big = fordVector(big);

    // insertion order result of jacobsthal
    std::vector<size_t> order = build_insertion_order(small.size());

    // insert small in big using binary search and jacobsthal
    for (size_t i = 0; i < small.size(); i++) {
        int idx = order[i];

        std::vector<int>::iterator it = binarySearchVector(big, small[idx]);
        big.insert(it, small[idx]);
    }

    // insert straggler
    if (straggler != -1){
        std::vector<int>::iterator it;

        it = std::lower_bound(big.begin(), big.end(), straggler);
        big.insert(it, straggler);
    }

    return big;
}

std::deque<int> PmergeMe::fordDeque(std::deque<int>& input){
    if (input.size() <= 1)
        return input;

    std::deque<std::pair<int,int> > pairs;
    std::deque<int> small, big;
    int straggler = -1;
    if (input.size() % 2 != 0){
        straggler = input.back();
        input.pop_back();
    }

    for (size_t i = 0; i + 1 < input.size(); i += 2)
        pairs.push_back(std::make_pair(input[i], input[i+1]));

    for (size_t i = 0; i < pairs.size(); i++)
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);

    for (size_t i = 0; i < pairs.size(); i++) {
        small.push_back(pairs[i].first);
        big.push_back(pairs[i].second);
    }

    big = fordDeque(big);

    std::vector<size_t> order = build_insertion_order(small.size());

    for (size_t i = 0; i < small.size(); i++) {
        int idx = order[i];
        std::deque<int>::iterator it = binarySearchDeque(big, small[idx]);
        big.insert(it, small[idx]);
    }

    if (straggler != -1){
        std::deque<int>::iterator it;

        it = std::lower_bound(big.begin(), big.end(), straggler);
        big.insert(it, straggler);
    }

    return big;
}
