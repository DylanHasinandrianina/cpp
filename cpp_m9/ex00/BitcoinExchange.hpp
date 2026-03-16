#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, double> db;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool loadDataBase(const std::string& filename);
    void parseInputFile(const std::string& filename);
    void parseLine(const std::string& line);

private:
    double findRate(const std::string& date);
    int parseDate(const std::string& date);
    int parseValue(const std::string& valueStr, double &outValue);
    std::string trim(const std::string& str);
};

#endif