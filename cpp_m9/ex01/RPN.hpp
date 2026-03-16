#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <string>

class RPN {
private:
    std::stack<int> stk;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void compute(const std::string& param);

private:
    bool isOperator(const std::string& token) const;
    bool applyOperator(const std::string& op);
};

#endif
