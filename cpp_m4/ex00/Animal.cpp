#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal constructor called\n";
}

Animal::Animal(std::string n){
    std::cout << "Animal " << n << "constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type){
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other){
    std::cout << "Animal assignment operator called\n";
    if (this != &other){
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal(){
    std::cout << "Animal destructor called\n";
}

void Animal::makeSound() const{
    std::cout << "Animal sound\n";
}

std::string Animal::getType() const{
    return (type);
}