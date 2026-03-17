#include "PmergeMe.hpp"

int main(int ac, char **av){

    //check args
    if (ac < 2){
        std::cerr << "Usage: ./PmergeMe <numbers...>\n";
        return 1;
    }
    PmergeMe pm;

    //parse tokens
    for (int i = 1; i < ac; i++){
        std::string token = av[i];
        if (!pm.parseToken(token)){
            std::cerr << "Error: invalid token '" << token << "'\n";
            return 1;
        }
    }

    //time vector, push in vector, sort in vector
    clock_t vstart = clock();
    std::vector<int> vInput;
    for (int i = 1; i < ac; i++){
        std::string token = av[i];
        vInput.push_back(std::atoi(token.c_str()));
    }
    std::vector<int> vSorted = pm.fordVector(vInput);
    clock_t vend = clock();
    double timeVectorSeconds = double(vend - vstart) / CLOCKS_PER_SEC;
    double timeVectorMicroseconds = timeVectorSeconds * 1000000;

    //time deque, push in deque, sort in deque
    clock_t dstart = clock();
    std::deque<int> dInput;
    for (int i = 1; i < ac; i++){
        std::string token = av[i];
        dInput.push_back(std::atoi(token.c_str()));
    }
    std::deque<int> dSorted = pm.fordDeque(dInput);
    clock_t dend = clock();
    double timeDequeSeconds = double(dend - dstart) / CLOCKS_PER_SEC;
    double timeDequeMicroseconds = timeDequeSeconds * 1000000;

    //prints
    std::cout << "Before: ";
    for (int i = 1; i < ac; i++){
        std::cout << av[i];
        if (i != ac - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (size_t i = 0; i < vSorted.size(); i++){
        std::cout << vSorted[i];
        if (i != vSorted.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vSorted.size()
                << " elements with std::vector : " << timeVectorMicroseconds << " us"
                << std::endl;
    std::cout << "Time to process a range of " << dSorted.size()
                << " elements with std::deque : " << timeDequeMicroseconds << " us"
                << std::endl;

    return 0;
}