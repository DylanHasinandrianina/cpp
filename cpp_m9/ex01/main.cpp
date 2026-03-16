#include "RPN.hpp"

int main(int ac, char **av){

    if (ac != 2){
        std::cerr << "Error: Usage: ./RPN <RPN expression>.\n";
        return 1;
    }

    RPN rpn;

    rpn.compute(av[1]);

    return 0;
}