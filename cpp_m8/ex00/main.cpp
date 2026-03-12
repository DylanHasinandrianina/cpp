#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>
#include <deque>

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

    try {
        std::vector<int>::iterator it = easyfind(v, 1);
        std::cout << "Found: " << *it << std::endl;

        it = easyfind(v, 10);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}