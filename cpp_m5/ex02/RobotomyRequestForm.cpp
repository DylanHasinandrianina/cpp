#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
        AForm("RobotomyRequestForm", 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){
    if (this != &copy){
        AForm::operator=(copy);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::executeAction() const{
    std::cout << "*DRRRRRRRRRRRR*\n";
    int random = std::rand();
    if (random % 2 == 0){
        std::cout << _target << " has been robotomized\n";
    }
    else
        std::cout << "The robotomy failed\n";
}
