#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, const int signGrade, const int execGrade) :
    _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){

    if (signGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150)
        throw AForm::GradeTooLowException();
    if (execGrade < 1)
        throw AForm::GradeTooHighException();
    if (execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) :
    _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade){
}

AForm& AForm::operator=(const AForm& copy){
    if (this != &copy){
        _signed = copy._signed;
    }
    return *this;
}

AForm::~AForm(){}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Form grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Form grade too low.";
}

const std::string& AForm::getName() const{
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getSignGrade() const{
    return _signGrade;
}

int AForm::getExecGrade() const{
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat& b){
    if (b.getGrade() > _signGrade){
        throw AForm::GradeTooLowException();
    }
    _signed = true;
}

std::ostream& operator<<(std::ostream &out, const AForm& f){
    out << "Name : " << f.getName() << ", Signed : " << f.isSigned()
        << ", Sign grade : " << f.getSignGrade() << ", Execute grade : " << f.getExecGrade()
        << ".";
    return out;
}

const char* AForm::NotSignedException::what() const throw(){
    return "The form is not signed.";
}

void AForm::execute(Bureaucrat const & executor) const{
    if (!_signed)
        throw AForm::NotSignedException();
    if (executor.getGrade() > _execGrade)
        throw AForm::GradeTooLowException();
    executeAction();
}