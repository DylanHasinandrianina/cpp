#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span{

    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;
    public:
        Span(unsigned int N);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();

        void addNumber(int i);
        int shortestSpan();
        int longestSpan();
        
        template <typename IT>
        void addNumbers(IT begin, IT end){
            for (IT it = begin; it != end; ++it)
                addNumber(*it);
        }

        class FullException : public std::exception{
            public :
                const char* what() const throw(){
                    return "The span is full, cannot add more number.\n";
                }
        };

        class NotEnoughElemException : public std::exception{
            public :
                const char* what() const throw(){
                    return "Not enough element to compute a span.\n";
                }
        };
};

#endif