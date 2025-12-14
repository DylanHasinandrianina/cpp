#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Nameless"){
    hp = 100;
    ep = 50;
    ad = 20;
    std::cout << "Nameless ScavTrap constructed\n";
}
//first the attributes is initialized in ClapTrap constructor but
//they will be replaced by what ScavTrap give them

ScavTrap::ScavTrap(std::string n) : ClapTrap(n){
    hp = 100;
    ep = 50;
    ad = 20;
    std::cout << "ScavTrap " << n << " constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
    std::cout << "ScavTrap copy constructor called\n";
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    std::cout << "ScavTrap assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}


ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << name << " Destroyed\n";
}

void ScavTrap::attack(const std::string& target){
    if (hp == 0){
        std::cout << "ScavTrap " << name << " is already dead, can't attack\n";
        return;
    }
    if (ep == 0){
        std::cout << "Not enough energy points, can't attack anymore\n";
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
            << ad << " points of damage." << std::endl;
    ep--;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode.\n";
}