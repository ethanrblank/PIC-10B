//@class TreeIterator acts as an iterator, used to traverse or crawl through a tree. ++ and -- operators have been overloaded to go to the respective nodes and several comparison oeprators.

#ifndef TreeIterator_hpp
#define TreeIterator_hpp

#include <cassert>
#include "TreeNode.hpp"
#include "BinarySearchTree.hpp"

class TreeNode;
class BinarySearchTree;

class TreeIterator {
public:
    TreeIterator();
    int operator*() const;
    TreeIterator& operator++();
    TreeIterator operator++(int unused);
    TreeIterator& operator--();
    bool operator==(const TreeIterator &b) const;
    bool operator !=(const TreeIterator &b) const;
private:
    TreeNode* position;
    BinarySearchTree* container;
    friend class BinarySearchTree;
    friend class TreeNode;
};

#endif /* TreeIterator_hpp */
