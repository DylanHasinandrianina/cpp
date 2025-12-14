#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Nameless"){
    hp = 100;
    ep = 100;
    ad = 30;
    std::cout << "Nameless FragTrap constructed\n";
}

FragTrap::FragTrap(std::string n) : ClapTrap(n){
    hp = 100;
    ep = 100;
    ad = 30;
    std::cout << "FragTrap " << n << " constructed\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
    std::cout << "FragTrap copy constructor called\n";
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    std::cout << "FragTrap assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << name << " Destroyed\n";
}

void FragTrap::attack(const std::string& target){
    if (hp == 0){
        std::cout << "FragTrap " << name << " is already dead, can't attack\n";
        return;
    }
    if (ep == 0){
        std::cout << "Not enough energy points, can't attack anymore\n";
        return;
    }
    std::cout << "FragTrap " << name << " attacks " << target << ", causing "
            << ad << " points of damage." << std::endl;
    ep--;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << name << " requests a positive HIGH FIVE!\n";
}