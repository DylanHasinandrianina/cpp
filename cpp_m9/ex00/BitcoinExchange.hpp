#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

std::map<std::string, double> loadDataBase(std::string DataBaseFile);
int parseInputFile(std::string InputFile, std::map<std::string, double> db);


#endif