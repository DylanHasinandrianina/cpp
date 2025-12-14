#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* newz;

    newz = new Zombie(name);
    return (newz);
}