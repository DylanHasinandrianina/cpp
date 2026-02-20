#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N){}

Span::Span(const Span& copy){
    _maxSize = copy._maxSize;
    _numbers = copy._numbers;
}

/*here i dont have to clear the container because it handles everything:
    - clears old data
    - deallocates old memory
    - allocates new memory
    - copies elements*/
Span& Span::operator=(const Span& copy){
    if (this != &copy){
        _maxSize = copy._maxSize;
        _numbers = copy._numbers;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int i){
    if (_numbers.size() >= _maxSize)
        throw FullException();
    _numbers.push_back(i);
}

int Span::shortestSpan(){

    if (_numbers.size() < 2)
        throw NotEnoughElemException();
    std::sort(_numbers.begin(), _numbers.end());
    int minDiff = std::numeric_limits<int>::max();
    for (size_t i = 0; i < _numbers.size() - 1; i++){
        int tmp = _numbers[i + 1] - _numbers[i];
        if (tmp < minDiff)
            minDiff = tmp;
    }
    return (minDiff);
}

int Span::longestSpan(){
    if (_numbers.size() < 2)
        throw NotEnoughElemException();
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    int maxDiff = max - min;
    return (maxDiff);
}