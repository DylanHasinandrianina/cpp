#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base* generate(void){

    int r = rand() % 3;

    if (r == 0)
        return (new A());
    else if (r == 1)
        return (new B());
    else if (r == 2)
        return (new C());
    else{
        std::cout << "Random generator error.\n";
        return NULL;
    }
}

void identify(Base* p){
    A* a;
    B* b;
    C* c;

    a = dynamic_cast<A*>(p);
    b = dynamic_cast<B*>(p);
    c = dynamic_cast<C*>(p);

    if (a)
        std::cout << "The actual type of the object pointed to by p is : A\n";
    else if (b)
        std::cout << "The actual type of the object pointed to by p is : B\n";
    else if (c)
        std::cout << "The actual type of the object pointed to by p is : C\n";
    else
        std::cout << "Other type\n";
}

void identify(Base& p){
    try{
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "The actual type of the object referenced by p is : A\n";
        return;
    }
    catch(...){}
    try{
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "The actual type of the object referenced by p is : B\n";
        return;
    }
    catch(...){}
    try{
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "The actual type of the object referenced by p is : C\n";
        return;
    }
    catch(...){}
}