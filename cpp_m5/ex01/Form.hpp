#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form{

    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;
    
    public:
        Form(std::string name, const int signGrade, const int execGrade);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        const std::string& getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream &out, const Form& f);

#endif