

#include "TreeIterator.hpp"

TreeIterator::TreeIterator() {
    position = nullptr;
    container = nullptr;
}

TreeIterator& TreeIterator::operator++() {
    assert(position != nullptr);
    if(position->right != nullptr)
        position = position->right;
    return *this;
}

TreeIterator& TreeIterator::operator--() {
    assert(position != nullptr);
    if (position->left != nullptr)
        position = position->left;
    return *this;
}

TreeIterator TreeIterator::operator++(int unused) {
    assert (position != nullptr);
    TreeIterator clone = *this;
    ++(clone);
    return clone;
}

bool TreeIterator::operator==(const TreeIterator &b) const {
    return position == b.position;
}

bool TreeIterator::operator!=(const TreeIterator &b) const {
    return !(position == b.position);
}


int TreeIterator::operator*() const {
    return position->data;
}
