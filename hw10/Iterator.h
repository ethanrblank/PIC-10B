//
//  Iterator.h
//  hw10
//
//  Created by Ethan Blank on 12/2/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h


#include "Node.h"
#include "List.h"
#include <cassert>

template<typename T>
class List<T>;
class Node<T>;

class Iterator {
public:
    Iterator();
    T operator*() const;
    Iterator<T>& operator++();
    Iterator<T> operator++(int unused);
    Iterator<T>& operator--();
    Iterator<T> operator--(int unused);
    bool operator==(const Iterator<T>& b) const;
private:
    Node<T>* position;
    List<T>* container;
    friend class List<T>;
};




#endif /* Iterator_h */
