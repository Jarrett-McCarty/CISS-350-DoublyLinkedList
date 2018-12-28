// File   : Deque.h
// Author : Jarrett McCarty

#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include "DLList.h"

class UnderflowError // An UnderflowError object is thrown
{
public:
    const char * what ()  const throw ()
    {
        return "UnderFlowError\n";
    }
};                   // if you execute any operation to
                     // remove a value from a deque that is
                     // empty.

template < typename T >
class Deque
{
public:
    Deque()
    {
        DLList< T > list;
    }
    void push_front(T k)
    {
        list.insert_head(k);
    }
    void push_back(T k)
    {
        list.insert_tail(k);
    }
    T front() const
    {
        if (is_empty()) throw UnderflowError();
        return list.front();
    }
    T & front()
    {
        if (is_empty()) throw UnderflowError();
        return list.front();
    }
    T back() const
    {
        if (is_empty()) throw UnderflowError();
        return list.back();
    }
    T & back()
    {
        if (is_empty()) throw UnderflowError();
        return list.back();
    }
    int size()
    {
        return list.size();
    }
    bool is_empty()
    {
        return list.is_empty();
    }
    void pop_front()
    {
        if (is_empty()) throw UnderflowError();
        list.remove_head();
    }
    void pop_back()
    {
        if (is_empty()) throw UnderflowError();
        list.remove_tail();
    }
    void clear()
    {
        if (is_empty()) throw UnderflowError();
        list.clear();
    }
    DLNode< T > * get_head_sen()
    {
        return list.head_sentinel();
    }
private:
    DLList< T > list;
};

#endif

