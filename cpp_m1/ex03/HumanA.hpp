#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{

    private:
        std::string nameA;
        Weapon &weaponA;
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
};

#endif

/*
HumanA use reference to its weapon so first,
the weapon class and the humanA class in main shared the same memory
-------------------------------------------------------------------
If you call club.setType("axe"),
HumanA’s weapon automatically becomes "axe" too
--------------------------------------------------------------------
and second, because weaponA cant be null (always armed)
-> reference cant be NULL
*/