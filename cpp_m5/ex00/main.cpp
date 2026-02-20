#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;
        a.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-------------------" << std::endl;

    try
    {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-------------------" << std::endl;

    try
    {
        Bureaucrat c("Charlie", 42);
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-------------------" << std::endl;

    try
    {
        Bureaucrat d("Invalid", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
