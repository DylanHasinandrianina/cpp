#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Bob");
    ClapTrap b("Alice");

    a.attack("Alice");
    b.takeDamage(5);

    b.beRepaired(3);
    a.takeDamage(15);
    a.attack("Alice");

    return 0;
}
