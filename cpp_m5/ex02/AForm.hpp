#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm{

    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;
    
    public:
        AForm(std::string name, const int signGrade, const int execGrade);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        ~AForm();

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

        class NotSignedException : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        void execute(Bureaucrat const & execitor) const;
        virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream &out, const AForm& f);

#endif