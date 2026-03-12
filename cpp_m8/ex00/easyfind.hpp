#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Not found in the container";
        } 
};

template <typename T>
typename T::iterator easyfind(T& container, int value){
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it != container.end()){
        return it;
    }
    else
        throw(NotFoundException());
}

#endif