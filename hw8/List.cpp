#include "List.h"

List::List() {
    first = nullptr;
    last = nullptr;
}

//List::~List() {
//    delete this;
//}


void List::insert(Iterator pos, int i) {
    Node* after = pos.position;
    Node* before = after->previous;
    Node* new_node = new Node(i);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node;
    if (before == nullptr)
        first = new_node;
    else
        before->next = new_node;
    
}

Iterator List::erase(Iterator pos) {
    Node* remove = pos.position;
    Node* before = remove->previous;
    Node* after = remove->next;
    if (remove == first)
        first = after;
    else
        before->next = after;
    if (remove == last)
        last = before;
    delete remove;
    Iterator r;
    r.position = after;
    r.container = this;
    return r;
}

Iterator List::begin() {
    Iterator iter;
    iter.position = first;
    iter.container = this;
    return iter;
}

Iterator List::end() {
    Iterator iter;
    iter.position = nullptr;
    iter.container = this;
    return iter;
}
