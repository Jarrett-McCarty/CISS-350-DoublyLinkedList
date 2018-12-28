// File   : test.cpp
// Author : Jarrett McCarty

#include <iostream>
#include "Deque.h"

int main()
{

    Deque< int > deque;
    try
    {
        deque.push_front(5);
        deque.push_back(6);
        int x = deque.front(); // x = 5
        std::cout << x << '\n';
        deque.front() = 4; // front of deque is now 4
        std::cout << deque.front() << '\n';
        int y = deque.back(); // y = 6
        std::cout << y << '\n';
        deque.back() = 7; // back of deque is 7
        std::cout << deque.back() << '\n';
        deque.pop_front(); // deque has now 1 value, i.e., 7
        deque.pop_back(); // deque is now empty
        int size = deque.size(); // size is zero
        std::cout << size << '\n';
        bool b = deque.is_empty(); // b is true
        std::cout << b << '\n';
        deque.push_front(1);
        deque.push_front(1);
        deque.push_front(1);
        deque.clear(); // deque is now empty
    }
    catch (UnderflowError & e)
    {
        std::cout << e.what();
    }
    return 0;
}
