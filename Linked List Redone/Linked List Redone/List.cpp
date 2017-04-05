//
//  List.cpp
//  Linked List Redone
//
//  Created by Ethan Blank on 12/21/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#include "List.h"

List::List() {
    first = nullptr;
    last = nullptr;
    size = 0;
}

List::~List() {
    for (Iterator start = begin(), stop = end(); start != stop; ++start) {
        delete start.position;
    }
}

Iterator List::insert(Iterator& pos, int data) {
    if (pos.position == nullptr) {
        Node* new_node = new Node(data);
        if (last == nullptr) {
            first = new_node;
            last = new_node;
        }
        else {
            new_node->previous = last;
            last->next = new_node;
            last = new_node;
        }
        pos.position = new_node;
    }
    else {
        Node* new_node = new Node(data);
        Node* after = pos.position;
        Node* before = after->previous;
        new_node->previous = before;
        new_node->next = after;
        after->previous = new_node;
        if (before == nullptr)
            first = new_node;
        else
            before->next = new_node;
        pos.position = new_node;
    }
    ++size;
    return pos;
}

Iterator List::erase(Iterator& pos) {
    Node* remove = pos.position;
    Node* before = remove->previous;
    Node* after = remove->next;
    if (remove == first)
        first = after;
    else
        before->next = after;
    if (remove == last)
        last = before;
    else
        after->previous = before;
    delete remove;
    pos.position = before;
    --size;
    return pos;
}

Iterator List::begin() {
    Iterator beginner;
    beginner.position = first;
    beginner.container = this;
    return beginner;
}

Iterator List::end() {
    Iterator ender;
    ender.position = nullptr;
    ender.container = this;
    return ender;
}

void List::push_back(int data) {
    Node* new_node = new Node(data);
    if (last == nullptr) {
        first = new_node;
        last = new_node;
    }
    else {
        new_node->previous = last;
        last->next = new_node;
        last = new_node;
    }
    ++size;
}

List List::reverse() {
    List reversed_list;
    for (Iterator begin = this->begin(), end = this->end(); begin != end; ++begin) {
        reversed_list.push_front(*begin);
    }
    return reversed_list;
}

void List::push_front(int data) {
    Node* new_node = new Node(data);
    if (first == nullptr) {
        first = new_node;
        last = new_node;
    }
    else {
        new_node->next = first;
        first->previous = new_node;
        first = new_node;
    }
    ++size;
}

int List::get_size() const {
    return size;
}

List& List::merge(List& other) {
    int alternator = 1;
    Iterator other_begin = other.begin();
    bool same_size = false;
    bool other_larger = false;
    if (size == other.size)
        same_size = true;
    if (size < other.size)
        other_larger = true;
        
    
    for (Iterator this_begin = begin(), this_end = end(); this_begin != this_end; ++this_begin) {
        if (!(alternator%2) && other_begin != nullptr) {
            insert(this_begin, *other_begin);
            ++other_begin;
        }
        ++alternator;
    }
    
    if (same_size)
        push_back(*other_begin);
    if (other_larger) {
        for (Iterator other_end = other.end(); other_begin != other_end; ++other_begin) {
            push_back(*other_begin);
        }
    }
    return *this;
}

void List::swap(List& other) {
    Node* this_first = first;
    Node* this_last = last;
    
    first = other.first;
    last = other.last;
    other.first = this_first;
    other.last = this_last;
}

Iterator List::minimum(const Iterator& from, const Iterator& to) {
    Iterator smallest = from;
    for (Iterator start = from, stop = to; start != stop; ++start) {
        if (*smallest < *start) {
            smallest = start;
        }
    }
    return smallest;
}

//void List::sort() {
//    for (Iterator start = begin(), stop = end(); start != stop; ++start) {
//        Node* bigger = start.position;
//        if (bigger > start)
//    }
//}

Node::Node() {
    data = 0;
    previous = nullptr;
    next = nullptr;
}

Node::Node(int init_data) {
    data = init_data;
    previous = nullptr;
    next = nullptr;
}

int Node::operator*() const {
    return data;
}

Iterator::Iterator() {
    position = nullptr;
    container = nullptr;
}

Iterator::Iterator(Node* init_node) {
    position = init_node;
    container = nullptr;
}

Iterator& Iterator::operator++() {
    if (position != nullptr) {
        Node* next_node = position->next;
        position = next_node;
    }
    return *this;
}

Iterator Iterator::operator++(int unused) {
    Iterator copy = *this;
    return ++copy;
}

Iterator& Iterator::operator--() {
    if (position != container->first) {
        Node* previous_node = position->previous;
        position = previous_node;
    }
    return *this;
}

Iterator Iterator::operator--(int unused) {
    Iterator copy = *this;
    return --copy;
}

int Iterator::operator*() const {
    return position->data;
}

bool Iterator::operator==(const Iterator& rhs) const {
    return position == rhs.position;
}

Iterator& Iterator::operator+=(int number) {
    for (int i = 0; i < number; ++i) {
        ++(*this);
    }
    return *this;
}

bool operator!=(const Iterator& lhs, const Iterator& rhs) {
    return !(lhs == rhs);
}
