#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
int easyfind(T& container, int value){
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); it++){
        if (*it == value)
            return 1;
    }
    return 0;
}

#endif