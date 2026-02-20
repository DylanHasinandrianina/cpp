#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 50);
    Bureaucrat charlie("Charlie", 150);

    std::cout << std::endl << "===== INTERN CREATES FORMS =====" << std::endl;

    Intern someRandomIntern;

    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    AForm* unknown = someRandomIntern.makeForm("unknown form", "test");

    std::cout << std::endl << "===== SIGNING FORMS =====" << std::endl;

    if (shrub)
        alice.signForm(*shrub);
    if (robot)
        bob.signForm(*robot);
    if (pardon)
        bob.signForm(*pardon);

    std::cout << std::endl << "===== EXECUTING FORMS =====" << std::endl;

    if (shrub)
        alice.executeForm(*shrub);

    if (robot)
        bob.executeForm(*robot);

    if (pardon)
        bob.executeForm(*pardon);


    delete shrub;
    delete robot;
    delete pardon;
    delete unknown;


    return 0;
}
