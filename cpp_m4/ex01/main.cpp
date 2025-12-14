#include "Cat.hpp"
#include "Dog.hpp"

int main(){
    std::cout << "\n======SUBJECT TESTS======\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n======ARRAY TESTS======\n";

    int size = 10;
    Animal* array[size];

    for (int i = 0; i < size/2; i++){
        array[i] = new Dog();
    }

    for (int j = size/2; j < size; j++){
        array[j] = new Cat();
    }

    for (int k = 0; k < size; k++){
        delete array[k];
    }

    std::cout << "\n======DEEP COPY TESTS======\n";

    Cat original;
    original.getBrain()->getIdeas()[0] = "original idea";
    
    Cat copy(original);

    std::cout << "\n------Before change------\n";
    std::cout << original.getBrain()->getIdeas()[0] << std::endl;
    std::cout << copy.getBrain()->getIdeas()[0] << std::endl;
    
    copy.getBrain()->getIdeas()[0] = "copy idea";

    std::cout << "\n------After change------\n";
    std::cout << original.getBrain()->getIdeas()[0] << std::endl;
    std::cout << copy.getBrain()->getIdeas()[0] << std::endl;
    
    return (0);
}