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

void vsort(std::string& arg){

    std::vector<int> input;
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> small;
    std::vector<int> big;

    //push the argument in the vector
    std::stringstream ss(arg);
    std::string token;
    while (ss >> token){
        input.push_back(std::atoi(token.c_str()));
    }

    //handle odd number of argument, because we cant assign .second of the last pair
    int stranggler = -1;
    if (input.size() % 2 != 0){
        stranggler = input.back();
        input.pop_back();
    }

    //group the elements into pairs
    for (int i = 0; i + 1 < input.size(); i++){
        pairs.push_back(std::make_pair(input[i], input[i + 1]))
    }

    //sort each pair
    for (int i = 0; i < pairs.size(); i++){

        if (pairs[i].first > pairs[i].second){
            int tmp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = tmp;
        }
    }

    //separate into two groups
    for (int i = 0; i < pairs.size(); i++){
        small.push_back(pairs[i].first);
        big.push_back(pairs[i].second);
    }

    //sort big

}