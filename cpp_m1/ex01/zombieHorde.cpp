#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){

    Zombie *zh;

    if (N <= 0)
        return (NULL);
    zh = new Zombie[N];
    for (int i = 0; i < N; i++){
        zh[i].setName(name);
    }
    return (zh);
}

    //here we need a default constructor so the zh = new Zombie[N]; wont fail