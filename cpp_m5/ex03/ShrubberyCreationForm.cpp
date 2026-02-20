#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137),
    _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy){
    if (this != &copy){
        AForm::operator=(copy);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executeAction() const{
    std::ofstream file ((_target + "_shrubberry").c_str());
    file <<
"              &&& &&  & &&\n"
"          && &\\/&\\|& ()|/ @, &&\n"
"          &\\/(\\/&/&||/& /_/)_&/_&\n"
"       &() &\\/&|()|/&\\/ '%\" & ()\n"
"      &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
"    &&   && & &| &| /& & % ()& /&&\n"
"      ()&_---()&\\&\\|&&-&&--%---()~\n"
"          &&     \\|||\n"
"                  |||\n"
"                  |||\n"
"            , -=-~  .-^- _\n";

    file.close();
}