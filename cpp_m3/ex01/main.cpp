#include "ScavTrap.hpp"

int main() {
    std::cout << "=====ClapTrap tests=====\n";
    ClapTrap a("Clap1");
    ClapTrap b("Clap2");

    a.attack("Alice");
    b.takeDamage(5);

    b.beRepaired(3);
    a.takeDamage(15);
    a.attack("Alice");

    std::cout << "=====ScavTrap tests=====\n";

    ScavTrap c("Scav1");
    c.attack("Target B");
    c.takeDamage(20);
    c.beRepaired(10);
    c.guardGate();

    ScavTrap d(c);
    d.attack("Copy target");

    ScavTrap e;
    e = c;
    e.attack("Assignment target");

    return 0;
}

