#ifndef INTERN_CPP
#define INTERN_CPP

#include <iostream>

class AForm;

class Intern{

    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& copy);
        ~Intern();

        AForm* makeForm(std::string formName, std::string formTarget);
};

#endif