#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : stk(other.stk) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        stk = other.stk;
    return *this;
}

RPN::~RPN() {}

void RPN::compute(const std::string& param){

    std::stringstream ss(param);
    std::string token;

    while (ss >> token){

        if (token.length() == 1 && std::isdigit(token[0])){
            stk.push(std::atoi(token.c_str()));
        }
        else if (isOperator(token)){
            if (!applyOperator(token))
                return;
        }
        else{
            std::cerr << "Error\n";
            return;
        }
    }

    if (stk.size() != 1){
        std::cerr << "Error\n";
        return;
    }

    std::cout << stk.top() << std::endl;
}


bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::applyOperator(const std::string& op) {
    if (stk.size() < 2) {
        std::cerr << "Error\n";
        return false;
    }

    int v2 = stk.top(); stk.pop();
    int v1 = stk.top(); stk.pop();

    if (op == "/" && v2 == 0) {
        std::cerr << "Error\n";
        return false;
    }

    int result;
    if (op == "+") result = v1 + v2;
    else if (op == "-") result = v1 - v2;
    else if (op == "*") result = v1 * v2;
    else if (op == "/") result = v1 / v2;

    stk.push(result);
    return true;
}