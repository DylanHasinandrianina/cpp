#include "iter.hpp"

void printInt(int& i){
    std::cout << i;
}

void printConstInt(const int& i){
    std::cout << i;
}

void toUpper(char& c){
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

int main(){
    int array[] = {1, 2, 3, 4, 5};
    const int carray[] = {6, 7, 8, 9, 10};
    char letters[] = {'a', 'b', 'c', 'x', 'y'};

    std::cout << "Print int array: ";
    iter(array, 5, printInt);
    std::cout << std::endl;

    std::cout << "Print const int array: ";
    iter(carray, 5, printConstInt);
    std::cout << std::endl;

    std::cout << "Template print: ";
    iter(array, 5, printTemp<int>);
    std::cout << std::endl;

    std::cout << "Chars before: ";
    iter(letters, 5, printTemp<char>);
    std::cout << std::endl;
    iter(letters, 5, toUpper);
    std::cout << "Chars after: ";
    iter(letters, 5, printTemp<char>);
    std::cout << std::endl;


    return 0;
}