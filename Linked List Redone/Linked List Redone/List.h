//
//  List.hpp
//  Linked List Redone
//
//  Created by Ethan Blank on 12/21/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#ifndef List_h
#define List_h


class List;
class Node;
class Iterator;

class List {
public:
    List();
    ~List();
    Iterator insert(Iterator&, int);
    Iterator erase(Iterator&);
    Iterator begin();
    Iterator end();
    void push_back(int);
    List reverse();
    void push_front(int);
    int get_size() const;
    List& merge(List&);
    void swap(List&);
    Iterator minimum(const Iterator& from, const Iterator& to);
    void sort();
    
private:
    Node* first;
    Node* last;
    int size;
    friend class Iterator;
};

class Node {
public:
    Node();
    Node(int);
    ~Node() {}
    int operator*() const;
    
private:
    int data;
    Node* previous;
    Node* next;
    friend class List;
    friend class Iterator;
};

class Iterator {
public:
    Iterator();
    Iterator(Node*);
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    Iterator& operator+=(int);
    int operator*() const;
    bool operator==(const Iterator&) const;
    
private:
    Node* position;
    List* container;
    friend class List;
};

bool operator!=(const Iterator&, const Iterator&);

#endif /* List_h */
