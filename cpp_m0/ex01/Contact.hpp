#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

class Contact{

    private: 
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact();
        ~Contact();
    
    void setContact(std::string fn, std::string ln,
            std::string nn, std::string pn,
            std::string ds);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickame() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif