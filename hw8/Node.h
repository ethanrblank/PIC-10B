//
//  Node.hpp
//  hw8
//
//  Created by Ethan Blank on 11/15/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#ifndef Node_h
#define Node_h

class Node {
public:
    Node();
    Node(int i);
    int operator*() const;
private:
    int data;
    Node* previous;
    Node* next;
    friend class List;
    friend class Iterator;
};

#endif /* Node_h */
