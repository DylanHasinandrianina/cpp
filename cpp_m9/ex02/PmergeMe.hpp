#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <limits>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // main methods
    bool addToken(const std::string& token);
    std::vector<int> fordVector(std::vector<int>& input);
    std::deque<int> fordDeque(std::deque<int>& input);
    std::vector<size_t> build_insertion_order(size_t n);


private:
    std::vector<size_t> jacobsthal_indices(size_t n);
};

#endif