#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{

    private:
        Contact contact[8];
        int count;
        int oldest;
    
    public:
        PhoneBook();
        ~PhoneBook();

    void addContact(Contact ct);
    std::string truncate(std::string str);
    void displayContacts();
    void showOneContact(int index);
    int getCount() const;

};

#endif