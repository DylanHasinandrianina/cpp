#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage : ./btc <inputFile>\n";
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.loadDataBase("data.csv"))
        return 1;

    btc.parseInputFile(argv[1]);

    return 0;
}