#include "Zombie.hpp"

int main(){

    Zombie* zh;
    int N = 10;

    zh = zombieHorde(N, "dylan");
    for (int i = 0; i < N; i++){
        zh[i].announce();
    }
    delete[] zh;
    return (0);
}

//to delete an array we use delete[]