#include "Weapon.hpp"

Weapon::Weapon(std::string t) : type(t){
}

Weapon::~Weapon(){
}

const std::string& Weapon::getType(){
    
    return (type);
}

//the const here means that we cant modify the string by using the returned reference
//if there is a last const, it means that the function promise to not modify the object itself

void Weapon::setType(std::string newType){

    type = newType;
}