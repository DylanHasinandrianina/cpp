#include "BitcoinExchange.hpp"

int main(int ac, char **av){

    if (ac != 2){
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    std::map<std::string, double> db = loadDataBase("data.csv");

    std::string inputFile = av[1];
    if (!parseInputFile(inputFile, db))
        return 1;
    return 0;
}