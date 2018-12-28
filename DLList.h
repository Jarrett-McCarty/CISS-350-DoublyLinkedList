// File   : DLList.h
// Author : Jarrett McCarty

#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include <utility>
#include "DLNode.h"

class IndexError
{
public:
    const char * what () const throw ()
    {
        return "Caught IndexError\n";
    }
};

class ValueError
{
public:
    const char * what () const throw ()
    {
        return "Caught ValueError\n";
    }
};


template < typename T >
class DLList
{
public:
DLList()
{
    size_ = 0;
    head_sentinel = new DLNode< T >;
    tail_sentinel = new DLNode< T >;
    head_sentinel->set_next(tail_sentinel);
    tail_sentinel->set_prev(head_sentinel);
}
    /* Copy Constructor */
    DLList(const DLList & src)
    {
        head_sentinel = new DLNode< T >;
        tail_sentinel = new DLNode< T >;
        head_sentinel->set_next(tail_sentinel);
        tail_sentinel->set_prev(head_sentinel);
        DLNode< T > * p = src.head_sentinel->get_next();
        while (p != NULL)
        {
            insert_tail(p->get_key());
            p = p->get_next();
        }
        size_ = src.size_;
    }
    
    ~DLList()
    {
        clear();
        delete head_sentinel;
        delete tail_sentinel;
    }
    static bool debug_printing;
    /* Overloaded assignment operator */
    DLList & operator =(const DLList & rhs)
        {
            clear();
            DLNode< T > * iterator = rhs.head_sentinel->get_next();
            while (iterator)
            {
                T obj = iterator->get_key();
                insert_tail(obj);
                iterator = iterator->get_next();
            }
            return *this;
        }
    
    DLNode< T > * get_head_sentinel() const
    {
        return head_sentinel;
    }
    DLNode< T > * get_tail_sentinel() const
    {
        return tail_sentinel;
    }
    
    bool is_empty() const
    {
        return (size() == 0);
    }
    void insert_head(T k)
    {
        if (is_empty())
        {
            DLNode< T > * newN = new DLNode< T >(k);
            head_sentinel->set_next(newN);
            tail_sentinel->set_prev(newN);
        }
        else
        {
            DLNode< T > * act = head_sentinel->get_next();
            DLNode< T > * newN = new DLNode< T >(k, act);
            act->set_prev(newN);
            head_sentinel->set_next(newN);
        }
        ++size_;
    }
    void insert_tail(T k)
    {
        if (is_empty())
        {
            DLNode< T > * p = new DLNode< T >(k);
            head_sentinel->set_next(p);
            tail_sentinel->set_prev(p);
        }
        else
        {
            DLNode< T > * p = tail_sentinel->get_prev();
            DLNode< T > * q = new DLNode< T >(k, NULL, p);
            p->set_next(q);
            tail_sentinel->set_prev(q);
        }
        ++size_;
    }
    T remove_head()
    {
        T x;
        DLNode< T > * p = head_sentinel->get_next();
        x = remove(p);
        return x;
    }
    T remove_tail()
    {
        T x;
        DLNode< T > * p = tail_sentinel->get_prev();
        x = remove(p);
        return x;
    }
    
    T remove(DLNode< T > * n)
    {
        T x;
        if (is_empty())
        {
            throw ValueError();
        }
        DLNode< T > * p = tail_sentinel->get_prev();
        while (p != NULL)
        {
            if (p == n)
            {
                break;
            }
            p = p->get_prev();
        }
        if (p == NULL)
        {
            throw ValueError();
        }
        else
        {
            DLNode< T > * aft = p->get_next();
            DLNode< T > * bef = p->get_prev();
            x = p->get_key();
            if (aft == NULL)
            {
                tail_sentinel->set_prev(bef);
            }
            else
            {
                aft->set_prev(bef);
            }
            if (bef == NULL)
            {
                head_sentinel->set_next(aft);
            }
            else
            {
                bef->set_next(aft);
            }
            delete p;
        }
        --size_;
        return x;
    }
    
    DLNode< T > * find(T k) const
    {
        if (is_empty()) throw ValueError();
        DLNode< T > * p = head_sentinel->get_next();
        while (p != NULL)
        {
            if (p->get_key() == k)
            {
                return (p);
            }
            p = p->get_next();
        }
        throw ValueError();
    }
    int size() const
    {
        
        return size_;
    }
    void clear()
    {
        while (!is_empty())
        {
            remove_tail();
        }
    }
    T operator[](int pos) const
    {
        if (pos < 0) throw IndexError();
        
        DLNode< T > * temp = head_sentinel->get_next();
        int i = 0;
        while (temp != NULL)
        {
            if (i == pos)
            {
                return temp->get_key();
            }
            ++i;
            temp = temp->get_next();
        }
        throw IndexError();
         
    }
    T & operator[](int pos) 
    {
        if (pos < 0) throw IndexError();
        
        DLNode< T > * temp = head_sentinel->get_next();
        int i = 0;
        while (temp != NULL)
        {
            if (i == pos)
            {
                return temp->get_key();
            }
            ++i;
            temp = temp->get_next();
        }
        throw IndexError();
         
    }
    void insert_before(DLNode< T > * src, T k)
    {
        if (is_empty())
        {
            throw ValueError();
        }
        DLNode< T > * p = head_sentinel->get_next();
        while (p != NULL)
        {
            if (p == src)
            {
                break;
            }
            p = p->get_next();
        }
        if (p == NULL)
        {
            throw ValueError();
        }
        else
        {
            DLNode< T > * bef = p->get_prev();
            DLNode< T > * newN = new DLNode< T >(k, p, bef);
            if (bef == NULL)
            {
                head_sentinel->set_next(newN);
            }
            else
            {
                bef->set_next(newN);
            }
            p->set_prev(newN);
        }
        ++size_;
    }
    bool insert_after(DLNode< T > * src, T k)
    {
        if (is_empty())
        {
            throw ValueError();
        }
        DLNode< T > * p = head_sentinel->get_next();
        while (p != NULL)
        {
            if (p == src)
            {
                break;
            }
            p = p->get_next();
        }
        if (p == NULL)
        {
            throw ValueError();
        }
        else
        {
            DLNode< T > * aft = p->get_next();
            DLNode< T > * newN = new DLNode< T >(k, aft, p);
            if (aft == NULL)
            {
                tail_sentinel->set_prev(newN);
            }
            else
            {
                aft->set_prev(newN);
            }
            p->set_next(newN);
        }
        ++size_;
    }
    /* Overloaded == operator */
    bool operator ==(const DLList & rhs)
    {
        if (size_ == 0 && rhs.size_ == 0)
        {
            return true;
        }
        DLNode< T > * p = head_sentinel->get_next();
        DLNode< T > * q = rhs.head_sentinel->get_next();
        while (p != NULL)
        {
            if (p->get_key() != q->get_key())
            {
                return false;
            }
            p = p->get_next();
            q = q->get_next();
            
        }
        return true;
    }
    /* Overloaded != operator */
    bool operator !=(const DLList & rhs)
    {
        return !(*this == rhs);
    }
    /* Returns the front of the list */
    T front() const
    {
        return head_sentinel->get_next()->get_key();
    }
    T & front()
    {
        return head_sentinel->get_next()->get_key();
    }
    /* Returns the back fo the list */
    T back() const
    {
        return tail_sentinel->get_prev()->get_key();
    }
    T & back()
    {
        return tail_sentinel->get_prev()->get_key();
    }
    int set_size(int k)
    {
       return size_ = k;
    }
private:
    DLNode< T > * head_sentinel;
    DLNode< T > * tail_sentinel;
    int size_;
};


/* Sets the value of debug printing */
template < typename T >
bool DLList< T >::debug_printing(true);

/* Overloaded << operator for printing */
template < typename T >
std::ostream & operator <<(std::ostream & cout, const DLList< T > & list)
{
    DLNode< T > * p = list.get_head_sentinel();
    p = p->get_next();
    
    if (DLList< T >::debug_printing)
    {
        std::cout << "<DLList " << (&list) << ", head_sentinel: "
                  << (list.get_head_sentinel())
                  << ", tail_sentinel: "
                  << (list.get_tail_sentinel())
                  << ">\n";
        if (DLNode< T >::debug_printing)
        {
            while (p != NULL)
            {
                cout << (*p) << '\n';
                p = p->get_next();
            }
        }
    }
    else
    {
        if (list.size() == 0)
            std::cout << "[]";
        
        else
        {
            int i = 0;
            std::cout << "[";
            while (i < list.size())
            {
                std::cout << p->get_key();
                if (i < list.size() - 1)
                {
                    std::cout << ", ";
                }
                p = p->get_next();
                ++i;
            }
            std::cout << "]";
        }
    }
    return cout;
}


#endif

