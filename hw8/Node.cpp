//
//  Node.cpp
//  hw8
//
//  Created by Ethan Blank on 11/15/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#include "Node.h"

Node::Node() {
    data = 0;
    previous = nullptr;
    next = nullptr;
}

Node::Node(int i) {
    data = i;
    previous = nullptr;
    next = nullptr;
}

int Node::operator*() const {
    return data;
}
