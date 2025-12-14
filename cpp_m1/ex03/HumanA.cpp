#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : nameA(name), weaponA(weapon){
}

HumanA::~HumanA(){}

void HumanA::attack(){
    std::cout << nameA << " attackes with their " << weaponA.getType() << std::endl;
}
