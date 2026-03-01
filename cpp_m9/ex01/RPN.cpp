#include "RPN.hpp"

void RPN(std::string& param){

    std::stack<int> stk;

    std::stringstream ss(param);
    std::string token;

    while (ss >> token){

        if (token.length() == 1 && std::isdigit(token[0])){
            stk.push(std::atoi(token.c_str()));
        }
        else if (token == "+" || token == "-" ||
                token == "*" || token == "/"){
            if (stk.size() < 2){
                std::cerr << "Error\n";
                return;
            }
            int v2 = stk.top();
            stk.pop();
            int v1 = stk.top();
            stk.pop();
            if (token == "/" && v2 == 0){
                std::cerr << "Error\n";
                return;
            }

            int result;
            if (token == "+")
                result = v1 + v2;
            else if (token == "-")
                result = v1 - v2;
            else if (token == "*")
                result = v1 * v2;
            else if (token == "/")
                result = v1 / v2;
            stk.push(result);
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
    else
        std::cout << stk.top() << std::endl;
}
