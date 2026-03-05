#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array{
    private:
        T* _data;
        size_t _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        Array& operator=(const Array& copy);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        size_t size() const;
};


class Test{
    public:
        Test() : value(0) {}
        Test(int v) : value(v) {}

        int get() const { return value; }

    private:
        int value;
};

#include "Array.tpp"

#endif