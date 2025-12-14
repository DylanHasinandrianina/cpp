#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("nameless"), hp(10), ep(10), ad(0){
    std::cout << name << " ClapTrap Constructed\n";
}

ClapTrap::ClapTrap(std::string n) : name(n), hp(10), ep(10), ad(0){
    std::cout << "ClapTrap " << name << " Constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << "ClapTrap copy constructor called\n";
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << "ClapTrap assignment operator called\n";
    if (this != &other){
        this->name = other.name;
        this->hp = other.hp;
        this->ep = other.ep;
        this->ad = other.ad;
    }
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << name << " Destroyed\n";
}

void ClapTrap::attack(const std::string& target){
    if (hp == 0){
        std::cout << "ClapTrap " << name << " is already dead, can't attack\n";
        return;
    }
    if (ep == 0){
        std::cout << "Not enough energy points, can't attack anymore\n";
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
            << ad << " points of damage." << std::endl;
    ep--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hp == 0){
        std::cout << "ClapTrap " << name << " is already dead, can't take damage anymore\n";
        return;
    }
    std::cout << "ClapTrap " << name << " take damage of "
            << amount << " points." << std::endl;
    hp = (hp <= amount) ? 0 : hp - amount;
    std::cout << "ClapTrap " << name << " hit points is now : " << hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (hp == 0){
        std::cout << "ClapTrap " << name << " is already dead, can't repaire himself\n";
        return;
    }
    if (ep == 0){
        std::cout << "Not enough energy points, can't repaire anymore\n";
        return;
    }
    std::cout << "ClapTrap " << name << " gains " << amount << " points." << std::endl;
    hp = hp + amount;
    std::cout << "ClapTrap " << name << " hit points is now : " << hp << std::endl;
    ep--;
}