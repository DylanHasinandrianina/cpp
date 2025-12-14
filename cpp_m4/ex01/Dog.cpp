#include "Dog.hpp"

Dog::Dog() : Animal(){
    type = "Dog";
    std::cout << "Dog constructor called\n";
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other){
    std::cout << "Dog copy constructor called\n";
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other){
    std::cout << "Dog assignment operator called\n";
    if (this != &other){
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog(){
    std::cout << "Dog destructor called\n";
    delete brain;
}

void Dog::makeSound() const{
    std::cout << "WOAFFF\n";
}
