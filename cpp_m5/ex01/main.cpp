#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "===== VALID CREATION =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 10);
        Form tax("Tax Form", 20, 50);

        std::cout << alice << std::endl;
        std::cout << tax << std::endl;

        alice.signForm(tax);
        std::cout << tax << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== SIGN GRADE TOO LOW =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 100);
        Form secret("Secret Form", 50, 10);

        bob.signForm(secret);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== INVALID FORM CREATION =====" << std::endl;
    try
    {
        Form invalid("Invalid Form", 0, 200);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== INVALID BUREAUCRAT CREATION =====" << std::endl;
    try
    {
        Bureaucrat error("Error", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
