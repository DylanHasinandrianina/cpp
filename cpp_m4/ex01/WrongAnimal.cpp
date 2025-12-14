#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string n){
    std::cout << "WrongAnimal " << n << "constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type){
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    std::cout << "WrongAnimal assignment operator called\n";
    if (this != &other){
        this->type = other.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal sound\n";
}

std::string WrongAnimal::getType() const{
    return (type);
}