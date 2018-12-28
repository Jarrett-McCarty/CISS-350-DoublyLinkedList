// File   : DLNode.h
// Author : Jarrett McCarty

#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>

template < typename T >
class DLNode
{
public:
DLNode(const T & key = T(), DLNode * next = NULL, DLNode * prev = NULL)
        : key_(key), next_(next), prev_(prev)
    {}
    ~DLNode()
    {}
    
    static bool debug_printing;
    DLNode * const & get_next() const
    {
        return next_;
    }
    DLNode * const & get_prev() const
    {
        return prev_;
    }
    T get_key() const 
    {
        return key_;
    }
    T & get_key()
    {
        return key_;
    }
    void set_key(T k)
    {
        key_ = k;
    }
    DLNode * & set_next(DLNode< T > * n)
    {
        next_ = n;
    }
    DLNode * & set_prev(DLNode< T > * n)
    {
        prev_ = n;
    }
    
private:
    T key_;
    DLNode< T > * prev_;
    DLNode< T > * next_;
};

/* Intializes the debug printing variable */
template < typename T >
bool DLNode< T >::debug_printing(true);

/* Overloaded << operator for printing */
template < typename T >
std::ostream & operator <<(std::ostream & cout, const DLNode< T > & n)
{
    if (DLNode< T >::debug_printing)
    {
        cout << "<DLNode: " << (&n)
             << ", key: " << n.get_key()
             << ", prev: " << n.get_prev()
             << ", next: " << n.get_next() << ">";
    }
    else
    {
        
        cout << n.get_key();
    }
    return cout;
}


#endif

