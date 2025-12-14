#include "Zombie.hpp"

Zombie::Zombie(std::string n){
    name = n;
    std::cout << name << "zombie is created\n";
}

Zombie::~Zombie(){
    std::cout << name << "zombie is destroyed\n";
}

void Zombie::announce(){
    std::cout << name << " : BraiiiiiiinnnzzzZ...\n";
}