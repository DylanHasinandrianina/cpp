#include "Span.hpp"
#include <list>
#include <ctime>

int main()
{
    std::cout << "========SUBJECT TEST============\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "========OTHER TESTS=============\n";
    try {
        Span sp(10);

        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(8);
        vec.push_back(12);

        sp.addNumbers(vec.begin(), vec.end());

        std::cout << "After adding vector range:" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::list<int> lst;
        lst.push_back(20);
        lst.push_back(-5);

        sp.addNumbers(lst.begin(), lst.end());

        std::cout << "After adding list range:" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        sp.addNumber(100);
        sp.addNumber(111);

    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "========BIG NUMBER TESTS=============\n";

    std::srand(std::time(NULL));

    const unsigned int N = 10000;
    Span bigSpan(N);

    std::vector<int> numbers;
    for (unsigned int i = 0; i < N; ++i) {
        numbers.push_back(std::rand());
    }

    bigSpan.addNumbers(numbers.begin(), numbers.end());

    std::cout << "Added " << N << " random numbers to Span." << std::endl;

    try {
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    return 0;
}