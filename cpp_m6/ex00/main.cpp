#include <iostream>
#include "ScalarConverter.hpp"
#include <string>

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "Invalid arguments\n";
        return 1;
    }
    std::string l = av[1];
    ScalarConvert::convert(l);
    return 0;
}