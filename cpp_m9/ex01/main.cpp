#include "RPN.hpp"

int main(int ac, char **av){

    if (ac != 2){
        std::cerr << "Error: Usage: ./RPN <RPN expression>.\n";
        return 1;
    }

    std::string param = av[1];

    RPN(param);

    return 0;
}