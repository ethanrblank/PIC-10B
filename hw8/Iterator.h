//
//  Iterator.hpp
//  hw8
//
//  Created by Ethan Blank on 11/15/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h

#include "Node.h"
#include "List.h"

class List;

class Iterator {
public:
    Iterator();
    Iterator(Node* node);
    Iterator& operator++();
    Iterator& operator--();
    Iterator operator--(int i);
    Iterator operator++(int i);
    int operator*() const;
    
private:
    Node* position;
    List* container;
    friend class List;
    
};

#endif /* Iterator_hpp */
