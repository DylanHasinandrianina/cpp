#include "Zombie.hpp"

int main(){

    Zombie* heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    delete heapZombie;
    std::cout << "------------\n";
    randomChump("stackZombie");
    std::cout << "------------\n";

    return (0);
}