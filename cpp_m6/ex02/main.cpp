#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

int main(){

    std::srand(std::time(NULL));
    for (int i = 0; i < 5; i++){
        std::cout << "----- Test " << i + 1 << " -----\n";
        Base *b = generate();
        identify(b);
        identify(*b);
        delete b;
    }
    return 0;
}