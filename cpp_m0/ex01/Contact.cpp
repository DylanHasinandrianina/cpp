#include "Contact.hpp"

Contact::Contact (void){
}

Contact::~Contact (void){
}

void Contact::setContact(std::string fn, std::string ln,
    std::string nn, std::string pn,
    std::string ds){
    firstName = fn;
    lastName = ln;
    nickname = nn;
    phoneNumber = pn;
    darkestSecret = ds;
}

std::string Contact::getFirstName() const{
    return (firstName);
}

std::string Contact::getLastName() const{
    return (lastName);
}

std::string Contact::getNickame() const{
    return (nickname);
}

std::string Contact::getPhoneNumber() const{
    return (phoneNumber);
}

std::string Contact::getDarkestSecret() const{
    return (darkestSecret);
}