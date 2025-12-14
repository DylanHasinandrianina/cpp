#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command : ";
        if (!std::getline(std::cin, cmd))
        {
            std::cout << "\nYou pressed ^D. Exiting phonebook now." << std::endl;
            break;
        }
        if (cmd.empty())
            continue; 
        if (cmd == "ADD")
        {
            Contact ct;
            pb.addContact(ct);
        }
        else if (cmd == "SEARCH")
        {
            std::string input;
            int index;

            if (pb.getCount() == 0){
                std::cout << "No contact yet, you can use ADD first\n";
                continue;
            }
            pb.displayContacts();
            std::cout << "Enter the index of the contact: ";
            std::getline (std::cin, input);
            if (input.empty()){
                std::cout << "No index entered\n";
                continue;
            }
            int invalid = 0;
            for (size_t i = 0; i < input.size(); i++){
                if (!std::isdigit(input[i])){
                    invalid = 1;
                    break;
                }
            }
            if (invalid){
                std::cout << "invalid index\n";
                continue;
            }
            index = std::atoi(input.c_str());
            if (index < 0 || index >= pb.getCount()){
                std::cout << "That contact index doesn’t exist.\n";
                continue;
            }
            pb.showOneContact(index);
        }
        else if (cmd == "EXIT"){
            std::cout << "End of the program\n";
            break;
        }
        else
            std::cout << "Invalid command\n";
    }
    return (0);
}