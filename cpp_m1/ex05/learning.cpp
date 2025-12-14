#include <iostream>

// int f(int a, int b){
//     return (a + b);
// }

// int main(){
//     int (*p)(int n1, int n2);

//     p = &f;
//     int sum = p(1, 2);
//     std::cout << "the sum is : " << sum << std::endl;
//     return (0);
// }



// class A{
//     public:
//         void hello();
// };

// void A::hello(){
//     std::cout << "Hello\n";
// }

// int main(){

//     void (A::*pm) ();
//     pm = &A::hello;
//     A a;
//     A *ap = &a;
//     (ap->*pm)();
//     return (0);
// }

class B{
    public:
        void a(){std::cout << "debug\n";};
        void b(){std::cout << "info\n";};
        void c(){std::cout << "warn\n";};
};

int main(){

    std::string names[] = {"DEBUG", "INFO", "WARN"};
    void (B::*funcs[])() = {&B::a, &B::b, &B::c};
    B obj;
    std::string level = "DEBUG";
    for (int i = 0; i < 3; i++){
        if (level == names[i])
            (obj.*funcs[i])();
    }
    return (0);
}