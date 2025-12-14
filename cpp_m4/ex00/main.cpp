#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{

std::cout << "\n======SUBJECT TEST=====\n";
{
    std::cout << "\n-----subject main test-----\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "\n-----other subject required test-----\n";
    const WrongAnimal* k = new WrongCat();
    k->makeSound();
    delete k;
}

std::cout << "\n======OTHER TESTS=====\n";
{
    std::cout << "\n-----copy constructor test-----\n";
    Dog original;
    Dog copy(original);
    Cat originalC;
    Cat copyC(originalC);

    std::cout << "\n-----assignment test-----\n";
    Dog d1;
    Dog d2;
    d2 = d1;

    Cat c1;
    Cat c2;
    c2 = c1;
}

std::cout << "\n===== ARRAY OF ANIMALS (POLYMORPHIC) =====\n";
    {
        Animal* animals[4];

        for (int i = 0; i < 4; ++i) {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << "\n-- Make all animals sound --\n";
        for (int i = 0; i < 4; ++i)
            animals[i]->makeSound();

        std::cout << "\n-- Deleting animals --\n";
        for (int i = 0; i < 4; ++i)
            delete animals[i];
    }

return 0;
}