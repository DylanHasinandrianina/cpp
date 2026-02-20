#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
    if the grade is invalid, "throw" stop the constructor and the object is not created
    the nearest "catch" will handle that
*/
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    if (grade < 1){
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150){
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade){}

/*
    here we cant change the name value since it is in const.
*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
    if (this != &copy){
        _grade = copy._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const{
    return _name;
}

int Bureaucrat::getGrade() const{
    return _grade;
}

void Bureaucrat::incrementGrade(){
    if (_grade <= 1){
        throw Bureaucrat::GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade(){
    if (_grade >= 150){
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
}

/*
    here we have throw to say that the function will not throw anything
*/
const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Bureaucrat grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Bureaucrat grade too low";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b){
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

/*
    here we need to use try/catch since the be.Signed() function throw an exception
*/
void Bureaucrat::signForm(AForm& f){
    try{
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cout << _name << " couldn't sign " << f.getName() 
                << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const{
    try{
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch(std::exception & e){
        std::cout << _name << " couldn't execute " << form.getName() 
                << " because " << e.what() << std::endl;
    }
}
