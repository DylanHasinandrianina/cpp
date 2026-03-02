#include "PmergeMe.hpp"

int main(int ac, char **av){

    if (ac < 2){
        std::cerr << "Error.\n";
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < ac; i++){
        std::string token = av[i];
        if (!parseToken(token)){
            std::cerr << "Error\n";
            return 1;
        }
        input.push_back(std::atoi(token.c_str()));
    }

    std::vector<int> v = vsort(input);
    for (size_t i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}