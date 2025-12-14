#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    count = 0;
    oldest = 0;
}

PhoneBook::~PhoneBook(){
}

int PhoneBook::getCount() const {
    return count;
}

void PhoneBook::addContact(Contact ct){

    std::string fn, ln, nn, pn, ds;

    std::cout << "First name: ";
    std::getline(std::cin, fn);

    std::cout << "Last name: ";
    std::getline(std::cin, ln);

    std::cout << "Nickname: ";
    std::getline(std::cin, nn);

    std::cout << "Phone number: ";
    std::getline(std::cin, pn);

    std::cout << "Darkest secret: ";
    std::getline(std::cin, ds);

    if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty())
    {
        std::cout << "All field must be filled, contact not added\n";
        return;
    }
    ct.setContact(fn, ln, nn, pn, ds);
    if (count < 8)
    {
        contact[count] = ct;
        count++;
    }
    else
    {
        contact[oldest] = ct;
        oldest = (oldest + 1) % 8;
    }
    std::cout << "contact added\n";
}

std::string PhoneBook::truncate(std::string str){

    if (str.size() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}

void PhoneBook::displayContacts(){

    std::cout << std::setw(10) << "index" << "|"
            << std::setw(10) << "first name" << "|"
            << std::setw(10) << "last name" << "|"
            << std::setw(10) << "nickname" << "|" << std::endl;
    
    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                << std::setw(10) << truncate(contact[i].getFirstName()) << "|"
                << std::setw(10) << truncate(contact[i].getLastName()) << "|"
                << std::setw(10) << truncate(contact[i].getNickame()) << "|" << std::endl;
    }  
}

void PhoneBook::showOneContact(int index){

    std::cout << "First name: " << contact[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contact[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contact[index].getNickame() << std::endl;
    std::cout << "Phone number: " << contact[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contact[index].getDarkestSecret() << std::endl;
}
