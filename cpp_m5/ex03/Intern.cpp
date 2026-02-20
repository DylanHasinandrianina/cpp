#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& copy){
    (void)copy;
}

Intern& Intern::operator=(const Intern& copy){
    (void)copy;
    return *this;
}

Intern::~Intern(){}

static AForm* makeShubbery(const std::string& target){
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target){
    return new RobotomyRequestForm(target);
}

static AForm* makePresidential(const std::string& target){
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget){
    std::string name[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*all_forms[])(const std::string& ) = {&makeShubbery, &makeRobotomy, &makePresidential};

    for (int i = 0; i < 3; i++){
        if (name[i] == formName){
            std::cout << "Intern creates " << formName << std::endl;
            return all_forms[i](formTarget);
        }
    }

    std::cout << "The form name does not exist.\n";
    return NULL;
}