//
//  List.hpp
//  hw8
//
//  Created by Ethan Blank on 11/15/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#ifndef List_h
#define List_h

#include "Iterator.h"
#include "Node.h"

class Iterator;

class List {
public:
    List();
    ~List();
    void insert(Iterator pos, int i);
    Iterator erase(Iterator pos);
    Iterator begin();
    Iterator end();
    friend class Iterator;
private:
    Node* first;
    Node* last;
};

#endif /* List_hpp */
