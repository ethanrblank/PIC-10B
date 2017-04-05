/** @file hw10.cpp
 @author [Ethan Blank]
 @date [12/2/16]
 
 [This program utilizes 3 templated classes, Node, Iterator, and List, to create a Linked List of Point2D objects. The program then allows the user to manipulate the objects including inserting points, erasing points, and swapping points.]
 
 */

#include <iostream>
#include "Point2D.h"
#include <cassert>

template<typename T>
class Node;
template<typename T>
class List;
template<typename T>
class Iterator;

/**
 @class Node
 @brief A templated class that can be used as a Node within a List class. The class contains data and pointers to the next and previous nodes.
 **/
template<typename T>
class Node {
public:
    Node();
    Node(T new_data);
private:
    T data;
    Node<T>* previous;
    Node<T>* next;
    friend class List<T>;
    friend class Iterator<T>;
};

/**
 @class Iterator
 @brief This is a templated iterator class for the List class. The iterators contain a pointer to the node that they are at and a pointer to the list that it is a container for. The class contains ++ and -- operaters for traversing through the list.
 **/
template<typename T>
class Iterator {
public:
    Iterator();
    Iterator(Node<T>* some_node);
    T operator*();
    Iterator<T>& operator++();
    Iterator<T> operator++(int unused);
    Iterator<T>& operator--();
    Iterator<T> operator--(int unused);
    bool operator==(const Iterator<T>& b) const;
    bool operator!=(const Iterator<T>& b) const;
private:
    Node<T>* position;
    List<T>* container;
    friend class List<T>;
};

/**
 @class List
 @brief This is a customized, templated linked list class that contains Node pointers to the first and last objects in the object. The class contains member functions that can be used to manipulate the object and intiate iterators.
 **/
template<typename T>
class List {
public:
    List();
    ~List();
    void push_back(const T& data);
    Iterator<T> insert(Iterator<T> pos, T data);
    Iterator<T> erase(Iterator<T> pos);
    Iterator<T> begin();
    Iterator<T> end();
    void swap(List<T>& other);
    void reverse();
    void push_front(T data);
    T maximum() const;
    void downsize(List<T>& names);
private:
    Node<T>* first;
    Node<T>* last;
    friend class Iterator<T>;
    
};


int main() {
    std::cout << "Please inpput a set of x and y coordinates for points in a List (Enter the point (-1,-1) when you are finished): ";
    bool user_end = true;
    double x;
    double y;
    List<Point2D> myList;
    while (user_end) {
        std::cin >> x;
        std::cin >> y;
        if (x == -1 && y == -1)
            user_end = false;
        else {
            Point2D new_point(x,y);
            myList.push_back(new_point);
        }
    }
    std::cout << "Your list is" << std::endl;
    std::cout << "(";
    for(auto x: myList) {
        std::cout << x;
    }
    std::cout << ")" << std::endl;
    user_end = true;
    while (user_end) {
        std::cout << "Select an index for insertion (enter -1 when finished): ";
        int index;
        std::cin >> index;
        if (index == -1)
            user_end = false;
        else {
            std::cout << "x-value: ";
            double x;
            std::cin >> x;
            std::cout << "y-value: ";
            double y;
            std::cin >> y;
            Iterator<Point2D> position=myList.begin();
            Point2D another_point(x,y);
            if (index != 0) {
                for (int i = 1; i != index; ++i) {
                    (++position);
                }
            }
            myList.insert(position, another_point);
        }
    }
    std::cout << "The augmented List is" << std::endl << "(";
    for (Iterator<Point2D> a = myList.begin(), z = myList.end(); a != z; ++a) {
        std::cout << "(" << *a << "),";
    }
    std::cout << ")";
    return 0;
}

/** MEMBER FUNCTION DEFINITIONS **/
//NODE CLASS
/**
 @param void
 The default constructor for a Node<T> object
 **/
template<typename T>
Node<T>::Node() {
    data = NULL;
    previous = nullptr;
    next = nullptr;
}

/**
 @param new_data
 The regular constructor takes in an object of data type T and sets the next and previous pointers to nullptr
 **/
template<typename T>
Node<T>::Node(T new_data) {
    data = new_data;
    previous = nullptr;
    next = nullptr;
}

//LIST CLASS

/** @param void
 The default constructor for a linked list. Sets the first and last pointers to nullptr
 **/
template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
}

/** @param void
 Destructor for a List object. Removes the nodes from the heap once the list goes out of scope
 **/
template<typename T>
List<T>::~List() {
    Iterator<T> eraser = (*this).begin();
    while (eraser != (*this).end()){
        erase(eraser);
    }
}

/**
 @param pos
 @return Iterator
 
 Erases a given node from the list
 **/
template<typename T>
Iterator<T> List<T>::erase(Iterator<T> pos) {
    assert(pos.position != nullptr);
    Node<T>* remove = pos.position;
    Node<T>* before = remove->previous;
    Node<T>* after = remove->next;
    if (remove == first)
        first = after;
    else
        before->next = after;
    if (remove == last)
        last = before;
    else
        after->previous = before;
    delete remove;
    Iterator<T> r;
    r.position = after;
    r.container = this;
    return r;
}

/** 
 @param void
 Creates an iterator object at the beginning of the list.
 **/
template<typename T>
Iterator<T> List<T>::begin() {
    Iterator<T> iter;
    iter.position = first;
    iter.container = this;
    return iter;
}

/**
 @param void
 creates an iterator at the end of the list
 **/
template<typename T>
Iterator<T> List<T>::end() {
    Iterator<T> iter;
    iter.position = nullptr;
    iter.container = this;
    return iter;
}

/**
 @param data
 creates a new node and pushes it onto the back of the list
 **/
template<typename T>
void List<T>::push_back(const T& data) {
    Node<T>* new_node = new Node<T>(data);
    if (last == nullptr) {
        first = new_node;
        last = new_node;
    }
    else {
        new_node->previous = last;
        last->next = new_node;
        last = new_node;
    }
}

/**
 @param pos, s
 @return Iterator<T>
 
 inserts a node at the given position then returns an iterator one less than the position it inserted the new node at
 **/
template<typename T>
Iterator<T> List<T>::insert(Iterator<T> pos, T s) {
    if (pos.position == nullptr) {
        push_back(s);
        return --pos;
    }
    Node<T>* after = pos.position;
    Node<T>* before = after->previous;
    Node<T>* new_node = new Node<T>(s);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node;
    if (before == nullptr)
        first = new_node;
    else
        before->next = new_node;
    return --pos;
}

/**
 @param other
 sawps two nodes within two separate lists
 **/
template<typename T>
void List<T>::swap(List<T>& other) {
    Iterator<T> start = (*this).begin();
    Iterator<T> end = (*this).end();
    
    this->first = other->first;
    this->last = other->last;
    
    other->first = start;
    other->last = end;
    
}

/**@param data
 
 creates a new node and pushes it to the front of the list
 **/
template<typename T>
void List<T>::push_front(T data) {
    Node<T>* new_node = new Node<T>(data);
    first->previous = new_node;
    new_node->next = first;
    first = new_node;
}

/**
 @param void
 
 Reverses the elements within the list
 **/
template<typename T>
void List<T>::reverse() {
    Node<T>* temp = new Node<T>(1);
    Node<T>* temp_2 = new Node<T>(1);
    temp->previous = first;
    temp->next = last;
    temp_2->previous = first->next;
    temp_2->next = last->previous;
    first->next = temp->next;
    last->previous = temp->previous;
    first->previous = temp_2->previous;
    last->next = temp_2->next;
    delete temp; delete temp_2;
}


//ITERATOR CLASS

/** 
 @param void
 default constructor for an iterator object
 **/
template<typename T>
Iterator<T>::Iterator() {
    position = nullptr;
    container = nullptr;
}

/**
 @param some_node
 creates an iterator object with a given node
 **/
template<typename T>
Iterator<T>::Iterator(Node<T>* some_node) {
    position = some_node;
    container = nullptr;
}

/**
 @param void
 @return Iterator<T>&
 increments the iterator to the next node by 1
 **/
template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    assert(position != nullptr);
    position = position->next;
    return *this;
}

/**
 @param unused
 @return Iterator<T>
 increments the iterator to the next node by 1
 **/
template<typename T>
Iterator<T> Iterator<T>::operator++(int unused) {
    assert(position != nullptr);
    Iterator<T> clone(*this);
    ++(*this);
    return clone;
}

/**
 @param void
 @return Iterator<T>&
 decrements the iterator to the next node by 1
 **/
template<typename T>
Iterator<T>& Iterator<T>::operator--() {
    assert(position != container->first);
    if (position == nullptr)
        position = container->last;
    else
        position = position->previous;
    return *this;
}

/**
 @param unused
 @return Iterator<T>
 decrements the iterator to the next node by 1
 **/
template<typename T>
Iterator<T> Iterator<T>::operator--(int unused) {
    assert(position != container->first);
    Iterator<T> clone(*this);
    if (clone.position == nullptr)
        clone.position = clone.container->last;
    else
        clone.position = clone.position->previous;
    return clone;
}

/**
 @param void
 @return T
 returns the data within a given node
 **/
template<typename T>
T Iterator<T>::operator*() {
    assert(position != nullptr);
    return position->data;
}

/** 
 @param b
 @return bool
 overloaded == operator for comparing the position of two iterators
 **/
template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &b) const {
    return position == b.position;
}


/**
 @param b
 @return bool
 overloaded != operator for comparing the position of two iterators
 **/
template<typename T>
bool Iterator<T>::operator !=(const Iterator<T> &b) const {
    return !(position == b.position);
}


