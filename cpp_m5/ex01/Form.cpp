#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, const int signGrade, const int execGrade) :
    _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){

    if (signGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150)
        throw Form::GradeTooLowException();
    if (execGrade < 1)
        throw Form::GradeTooHighException();
    if (execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) :
    _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade){
}

Form& Form::operator=(const Form& copy){
    if (this != &copy){
        _signed = copy._signed;
    }
    return *this;
}

Form::~Form(){}

const char* Form::GradeTooHighException::what() const throw(){
    return "grade too high.";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "grade too low.";
}

const std::string& Form::getName() const{
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getSignGrade() const{
    return _signGrade;
}

int Form::getExecGrade() const{
    return _execGrade;
}

void Form::beSigned(const Bureaucrat& b){
    if (b.getGrade() > _signGrade){
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

std::ostream& operator<<(std::ostream &out, const Form& f){
    out << "Name : " << f.getName() << ", Signed : " << f.isSigned()
        << ", Sign grade : " << f.getSignGrade() << ", Execute grade : " << f.getExecGrade()
        << ".";
    return out;
}