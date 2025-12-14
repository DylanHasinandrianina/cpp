#include "HumanB.hpp"

HumanB::HumanB(std::string name) : nameB(name), weaponB(NULL){
}

HumanB::~HumanB(){}

void HumanB::attack(){

    if (weaponB)
        std::cout << nameB << " attackes with their " << weaponB->getType() << std::endl;
    else
    std::cout << nameB << " has no weapon" << std::endl;

}

void HumanB::setWeapon(Weapon& weapon){
    weaponB = &weapon;
}

/*here we use reference for the setWeapon s parameter to match the
main example and to make sure it point to the same memory as the weapon class*/