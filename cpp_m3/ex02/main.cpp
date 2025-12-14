#include "FragTrap.hpp"

int main() {
    std::cout << "\n===== ClapTrap tests =====\n";
    ClapTrap a("Clap1");
    ClapTrap b("Clap2");

    a.attack("Alice");
    b.takeDamage(5);

    b.beRepaired(3);
    a.takeDamage(15);
    a.attack("Alice");

    std::cout << "\n===== ScavTrap tests =====\n";

    ScavTrap c("Scav1");
    c.attack("Target B");
    c.takeDamage(20);
    c.beRepaired(10);
    c.guardGate();

    std::cout << "\n-- ScavTrap Copy Constructor --\n";
    ScavTrap d(c);
    d.attack("Copy target");

    std::cout << "\n-- ScavTrap Assignment Operator --\n";
    ScavTrap e;
    e = c;
    e.attack("Assignment target");

    std::cout << "\n===== FragTrap tests =====\n";
    
    FragTrap f("Frag1");
    f.attack("Target B");
    f.takeDamage(20);
    f.beRepaired(10);
    f.highFivesGuys();

    std::cout << "\n-- FragTrap Copy Constructor --\n";
    FragTrap g(f);
    g.attack("Copy target"); // FIXED

    std::cout << "\n-- FragTrap Assignment Operator --\n";
    FragTrap h;
    h = f;
    h.attack("Assignment target");

    return 0;
}
