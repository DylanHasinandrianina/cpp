#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <limits>
#include <ctime>
#include <utility> // std::make_pair
#include <algorithm> // std::lower_bound
#include <vector>
#include <deque>

int parseToken(std::string& token);
std::vector<int> fordVector(std::vector<int>& input);
std::deque<int> fordDeque(std::deque<int>& input);


#endif