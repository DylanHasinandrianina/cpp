#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "=====SUBJECT TEST=====\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
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
    std::stack<int> st(mstack);


    std::cout << "\n=====COPY AND CONST TEST=====\n";
    const MutantStack<int> cm(mstack);
    for (MutantStack<int>::const_iterator it = cm.begin(); it != cm.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "\n=====REVERSE TEST=====\n";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
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
    return 0;
}

