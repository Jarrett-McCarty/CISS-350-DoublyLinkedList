# File   : main.py
# Author : Jarrett McCarty

import DoublyLinkedList

if __name__ == '__main__':
    

    # Intitalize a list object from contructor
    xlist = DoublyLinkedList.DLList()
    
    # Insert value at the head of xlist
    xlist.insert_head(50)
    
    # Insert value at the tail of xlist
    xlist.insert_tail(100)
    
    # Print xlist's size
    print xlist.size()
    
    # Print if xlist is empty or not
    print xlist.is_empty()
    
    # Print xlist itself
    print xlist
    
    # Delete head of xlist
    xlist.delete_head()
    
    # Print xlist itself
    print xlist
    
    # Insert tail of xlist
    xlist.insert_tail(20)
    
    # Print xlist
    print xlist
    
    # Delete tail again
    xlist.delete_tail()
    
    # Print xlist
    print xlist
    
    # Print xlist's size
    print xlist.size()
    
    # Insert head 2 times then a tail
    xlist.insert_head(50)
    xlist.insert_head(150)
    xlist.insert_tail(200)
    
    # Print xlist
    print xlist
    
    # Find at which the values 50/99 are found in list return a reference/None 
    print xlist.find(50)
    print xlist.find(99)
    # Print xlist
    print xlist
    
    # Delete head and tail of xlist and store the values so you can print them
    y = xlist.delete_tail()
    x = xlist.delete_head()
    
    # Print xlist and the values that were just deleted
    print xlist
    print x, y
    
    # Print the len of xlist
    print len(xlist)
    
    # Intialize new list ylist
    ylist = DoublyLinkedList.DLList()
    
    # Insert head
    ylist.insert_head(70)
    
    # Return a Python list from the ylist and print
    xs = xlist.get_list()
    print xs
    
    # Print type to check if its a python list
    print type(xs)
    
    # Checks if xlist and ylist equal each other
    print (ylist == xlist)
    
    # Clear xlist and return it
    print xlist.clear()
    
    # Prints if xlist is empty or not
    print xlist.is_empty()

    # Returns None because xlist is empty
    print xlist.delete_head()
    
    # Print ylist
    print ylist
    
    # Add elements to ylist to check __retr__
    ylist.insert_head(1000)
    ylist.insert_tail(2000)
    ylist.insert_head(10000)
    print ylist
    print ylist.find(2000)
    print xlist.find(1000)
