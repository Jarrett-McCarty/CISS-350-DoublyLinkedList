# File   : DoublyLinkedList.py
# Author : Jarrett McCarty

class DoublyLinkedListNode(object):

    def __init__(self, value_=None, prev_=None, next_=None, is_sentinel=False):

        object.__init__(self)
        self.__value_ = value_
        self.__prev_ = prev_
        self.__next_ = next_
        self.__is_sentinel = is_sentinel
        
    def get_value(self):
        return self.__value_

    def set_value(self, value):
        self.__value_ = value
        
    value_ = property(get_value, set_value)

    def get_prev(self):
        return self.__prev_

    def set_prev(self, prev):
        self.__prev_ = prev

    prev_ = property(get_prev, set_prev)

    def get_next(self):
        return self.__next_

    def set_next(self, value):
        self.__next_ = value

    next_ = property(get_next, set_next)

    def get_sentinel(self):
        return self.__is_sentinel

    def set_sentinel(self, value):
        self.__is_sentinel = value

    is_sentinel = property(get_sentinel, None)

    def __repr__(self):
        return "<Node %s value:%s, prev:%s, next:%s>"% (id(self), self.__value_, id(self.__prev_), id(self.__next_))
    
    def __str__(self):
        return "%s" % self.__value_
    
    def is_sentinel(self):
        return self.__is_sentinel_

    def __eq__(self, node):
        return  self.get_value == node.value_

DLNode = DoublyLinkedListNode
    
class DoublyLinkedList(object):

    def __init__(self):
        head_sentinel = DLNode(is_sentinel=True)
        tail_sentinel = DLNode(is_sentinel=True)
        head_sentinel.set_next(tail_sentinel)
        tail_sentinel.set_prev(head_sentinel)
        self.__tail_sentinel = tail_sentinel
        self.__head_sentinel = head_sentinel

    def head(self):
        return self.__head_sentinel.next_

    def tail(self):
        return self.__tail_sentinel.prev_
        
    def __len__(self):
        return self.size()

    def size(self):
        count = 0
        curr = self.__head_sentinel.next_
        while curr is not None and curr != self.__tail_sentinel:
            count += 1
            curr = curr.next_

        return count
    
    def is_empty(self):
        return self.size() == 0

    def insert_head(self, val):
        node = DLNode(value_=val,
                      prev_=self.__head_sentinel,
                      next_=self.__head_sentinel.next_)
        self.__head_sentinel.next_.prev_ = node
        self.__head_sentinel.next_ = node
        #if self.is_empty():
           #node = DLNode(value_=val)
           #self.__head_sentinel.next_ = node
           #self.__tail_sentinel.prev_ = node
       #else:
        #    temp = DLNode()
         #   temp = self.__head_sentinel.next_
          #  node = DLNode(value_=val, next_=temp)
           # temp.prev_ = node
            #self.__head_sentinel.next_ = node
                
    def insert_tail(self, val):
        node = DLNode(value_=val,
                      prev_=self.__tail_sentinel.prev_,
                      next_=self.__tail_sentinel)
        self.__tail_sentinel.prev_.next_ = node
        self.__tail_sentinel.prev_ = node
        
        #if self.is_empty():
         #   node = DLNode(value_=val)
          #  self.__head_sentinel.next_ = node
           # self.__tail_sentinel.prev_ = node
        #else:
         #   temp = DLNode()
          #  temp = self.__tail_sentinel.prev_
           # node = DLNode(value_=val, prev_=temp)
           # temp.next_ = node
           # self.__tail_sentinel.prev_ = node
         
    def __repr__(self):
        output = ""
        iter_node = self.__head_sentinel.next_
        i = 0
        while i < self.size():
            output += str(iter_node)
            if i < self.size() - 1:
                output += " -> "
            iter_node = iter_node.next_
            i += 1
        return "[ " + output + " ]"

    def __eq__(self, n_list):
        iter_a = self.__head_sentinel.next_
        iter_b = n_list.__head_sentinel.next_
        while iter_a and iter_b:
            if iter_a.value_ != iter_b.value_:
                return False
            iter_a = iter_a.next_
            iter_b = iter_b.next_
        return True
    
    def delete_head(self):
        if self.is_empty():
            return None
        else:
            x = self.__head_sentinel.next_
            self.__head_sentinel = self.__head_sentinel.next_
            self.__head_sentinel.prev_ = None
            return x
        
    def delete_tail(self):
        if self.is_empty():
            return None
        else:
            x = self.__tail_sentinel.prev_
            self.__tail_sentinel = self.__tail_sentinel.prev_
            self.__tail_sentinel.next_ = None
            return x

    def find(self, val):
        if self.is_empty():
            return None
        x = 0
        iter_node = self.__head_sentinel
        while iter_node is not self.__tail_sentinel:
            if iter_node.value_ == val:
                return iter_node
            iter_node = iter_node.next_
            x += 1
            if x == self.size() + 1:
                return None
            
    def clear(self):
        while self.is_empty() == False:
            self.delete_tail()
        return self

    def get_list(self):
        xlist = []
        iter_node = self.__head_sentinel.next_
        i = 0
        while i < self.size():
            xlist.append(iter_node.value_)

            iter_node = iter_node.next_
            i += 1
        return xlist

DLList = DoublyLinkedList
