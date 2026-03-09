#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>

int main(){

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::list<int> l;
    l.push_back(6);
    l.push_back(7);
    l.push_back(8); 
    l.push_back(9);
    l.push_back(10);

    std::deque<int> d;
    d.push_back(11);
    d.push_back(12);
    d.push_back(13); 
    d.push_back(14);
    d.push_back(15);

    int result = easyfind(d, 6);
    if (result)
        std::cout << "Found.\n";
    else
        std::cout << "Not found.\n";
    return 0;
}