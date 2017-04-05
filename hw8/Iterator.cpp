//
//  Iterator.cpp
//  hw8
//
//  Created by Ethan Blank on 11/15/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#include "Iterator.h"

Iterator::Iterator() {
    position = nullptr;
    container = nullptr;
}

Iterator::Iterator(Node* node) {
    position = nullptr;
    container = nullptr;
    
    
}

Iterator& Iterator::operator++() {
    position = position->next;
    return *this;
}

Iterator& Iterator::operator--() {
    position = position->previous;
    return *this;
}

Iterator Iterator::operator--(int i) {

}

Iterator Iterator::operator++(int i) {

}
int Iterator::operator*() const {
    return position->data;
}
