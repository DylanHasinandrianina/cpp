#include "PmergeMe.hpp"

int parser(std::string& arg){

    if (arg.empty())
        return (0);
    
    std::stringstream ss(arg);
    std::string token;
    while (ss >> token){

        int i = 0;
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
        if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
            return 0;

        if (nbr < 0)
            return 0;
    }
    return 1;
}

std::vector<int> ford(std::vector<int>& seq){

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> small;
    std::vector<int> big;

    if (seq.size() <= 1)
        return seq;

    //handle odd number of argument, because we cant assign .second of the last pair
    int straggler = -1;
    if (seq.size() % 2 != 0){
        straggler = seq.back();
        seq.pop_back();
    }

    //group the elements into pairs
    for (int i = 0; i + 1 < seq.size(); i += 2){
        pairs.push_back(std::make_pair(seq[i], seq[i + 1]));
    }

    //sort each pair
    for (int i = 0; i < pairs.size(); i++){

        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    //separate into two groups
    for (int i = 0; i < pairs.size(); i++){
        small.push_back(pairs[i].first);
        big.push_back(pairs[i].second);
    }

    //sort big
    big = ford(big);

    //insert small
    for (int i = 0; i < small.size(); i++){
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

std::vector<int> vsort(std::string& arg){

    std::vector<int> input;

    //push the argument in the vector
    std::stringstream ss(arg);
    std::string token;
    while (ss >> token){
        input.push_back(std::atoi(token.c_str()));
    }

    return ford(input);

}