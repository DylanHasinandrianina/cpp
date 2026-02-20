#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    //Initialize random seed once for Robotomy
    std::srand(std::time(NULL));

    Bureaucrat alice("Alice", 50);
    Bureaucrat bob("Bob", 1);         // very high grade
    Bureaucrat charlie("Charlie", 150); // very low grade

    ShrubberyCreationForm treeForm("home");
    RobotomyRequestForm roboForm("Marvin");
    PresidentialPardonForm pardonForm("Zaphod");

    std::cout << "\n===== SIGNING FORMS =====\n";

    // Alice tries to sign all forms
    alice.signForm(treeForm);
    alice.signForm(roboForm);
    alice.signForm(pardonForm); // too low grade → prints exception

    // Bob signs remaining forms
    bob.signForm(roboForm);
    bob.signForm(pardonForm);

    std::cout << "\n===== EXECUTING FORMS =====\n";

    // Alice executes Shrubbery (allowed)
    alice.executeForm(treeForm);

    // Alice tries to execute Robotomy (too low)
    alice.executeForm(roboForm);

    // Bob executes Robotomy
    bob.executeForm(roboForm);

    // Bob executes Presidential Pardon
    bob.executeForm(pardonForm);

    // Charlie tries to execute Shrubbery (too low)
    charlie.executeForm(treeForm);

    return 0;
}
