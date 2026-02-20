#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "===== Default constructor =====" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    std::cout << "\n===== Sized constructor =====" << std::endl;
    Array<int> a(5);
    std::cout << "a.size() = " << a.size() << std::endl;

    for (size_t i = 0; i < a.size(); i++)
        a[i] = i * 10;

    std::cout << "a contents: ";
    for (size_t i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "\n===== Copy constructor =====" << std::endl;
    Array<int> b(a);

    std::cout << "b contents: ";
    for (size_t i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "\nModify b[0] = 999" << std::endl;
    b[0] = 999;

    std::cout << "a[0] = " << a[0] << " (should NOT change)" << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "\n===== Assignment operator =====" << std::endl;
    Array<int> c;
    c = a;

    std::cout << "c contents: ";
    for (size_t i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "\nModify c[1] = 777" << std::endl;
    c[1] = 777;

    std::cout << "a[1] = " << a[1] << " (should NOT change)" << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl;

    std::cout << "\n===== Const access =====" << std::endl;
    const Array<int> d(a);

    std::cout << "d contents: ";
    for (size_t i = 0; i < d.size(); i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;

    // d[0] = 5; // ❌ must not compile if const operator[] is correct

    std::cout << "\n===== Bounds checking =====" << std::endl;
    try {
        std::cout << a[100] << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== Different type =====" << std::endl;
    Array<std::string> s(3);
    s[0] = "Hello";
    s[1] = "Template";
    s[2] = "World";

    for (size_t i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
    std::cout << std::endl;

    std::cout << "\n===== End of tests =====" << std::endl;

    return 0;
}
