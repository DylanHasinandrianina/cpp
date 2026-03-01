#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "=====MUTANTSTACK TEST=====\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator itLst = mstack.begin();
    MutantStack<int>::iterator iteLst = mstack.end();
    ++itLst;
    --itLst;
    while (itLst != iteLst)
    {
        std::cout << *itLst << std::endl;
        ++itLst;
    }


    std::cout << "========LIST TEST=====\n";
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(lst);
    return 0;
}

