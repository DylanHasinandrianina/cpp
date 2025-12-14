#include "Cat.hpp"

Cat::Cat() : Animal(){
    type = "Cat";
    std::cout << "Cat constructor called\n";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat copy constructor called\n";
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other){
    std::cout << "Cat assignment operator called\n";
    if (this != &other){
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat(){
    std::cout << "Cat destructor called\n";
    delete brain;
}

void Cat::makeSound() const{
    std::cout << "MIAOUUU\n";
}

Brain* Cat::getBrain(){
    return (brain);
}