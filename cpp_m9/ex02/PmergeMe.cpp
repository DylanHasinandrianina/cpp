#include "PmergeMe.hpp"

int parseToken(std::string& token){

    if (token.empty())
        return (0);
    
    size_t i = 0;
    if (token[0] == '-' || token[0] == '+'){
        if (token.length() == 1)
            return 0;
        else
            i++;
    }

    for (; i < token.length(); i++){
        if (!std::isdigit(token[i]))
            return 0;
    }

    long nbr = std::atol(token.c_str());
    if (nbr < 0)
            return 0;
    if (nbr > std::numeric_limits<int>::max())
            return 0;
    return 1;
}

std::vector<size_t> jacobsthal_indices(size_t n){
    std::vector<size_t> jacs;
    size_t j0 = 0;
    size_t j1 = 1;
    while (j1 <= n){
        jacs.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    return jacs;

}

std::vector<int> fordVector(std::vector<int>& vInput){

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> small;
    std::vector<int> big;

    if (vInput.size() <= 1)
        return vInput;

    //handle odd number of argument, because we cant assign .second of the last pair
    int straggler = -1;
    if (vInput.size() % 2 != 0){
        straggler = vInput.back();
        vInput.pop_back();
    }

    //group the elements into pairs
    for (size_t i = 0; i + 1 < vInput.size(); i += 2){
        pairs.push_back(std::make_pair(vInput[i], vInput[i + 1]));
    }

    //sort each pair
    for (size_t i = 0; i < pairs.size(); i++){

        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    //separate into two groups
    for (size_t i = 0; i < pairs.size(); i++){
        small.push_back(pairs[i].first);
        big.push_back(pairs[i].second);
    }

    //sort big
    big = fordVector(big);

    //insert small
    for (size_t i = 0; i < small.size(); i++){
        std::vector<int>::iterator it;

        it = std::lower_bound(big.begin(), big.end(), small[i]);
        big.insert(it, small[i]);
    }

    //insert stranggler
    if (straggler != -1){
        std::vector<int>::iterator it;

        it = std::lower_bound(big.begin(), big.end(), straggler);
        big.insert(it, straggler);
    }

    return big;
}

std::deque<int> fordDeque(std::deque<int>& dInput){

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> small;
    std::deque<int> big;

    if (dInput.size() <= 1)
        return dInput;

    //handle odd number of argument, because we cant assign .second of the last pair
    int straggler = -1;
    if (dInput.size() % 2 != 0){
        straggler = dInput.back();
        dInput.pop_back();
    }

    //group the elements into pairs
    for (size_t i = 0; i + 1 < dInput.size(); i += 2){
        pairs.push_back(std::make_pair(dInput[i], dInput[i + 1]));
    }

    //sort each pair
    for (size_t i = 0; i < pairs.size(); i++){

        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    //separate into two groups
    for (size_t i = 0; i < pairs.size(); i++){
        small.push_back(pairs[i].first);
        big.push_back(pairs[i].second);
    }

    //sort big
    big = fordDeque(big);

    //insert small
    for (size_t i = 0; i < small.size(); i++){
        std::deque<int>::iterator it;

        it = std::lower_bound(big.begin(), big.end(), small[i]);
        big.insert(it, small[i]);
    }

    //insert stranggler
    if (straggler != -1){
        std::deque<int>::iterator it;

        it = std::lower_bound(big.begin(), big.end(), straggler);
        big.insert(it, straggler);
    }

    return big;
}