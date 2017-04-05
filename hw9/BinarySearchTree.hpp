//@class Binary search tree has several functions which insert TreeNodes into a collection of a binarysearchtree object. The cout commmand has been overloaded to print "bst" objects.

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "TreeNode.hpp"
#include "TreeIterator.hpp"
//#include <ostream>

class TreeIterator;

class BinarySearchTree {
    friend std::ostream& operator<<(std::ostream& out, const BinarySearchTree& bst);
public:
    BinarySearchTree();
    void insert(int data);
    void erase(int data);
    int count(int data) const;
    TreeIterator begin();
    TreeIterator end();
    void print() const;
    int smallest() const;
    int largest() const;
private:
    TreeNode* root;
};

#endif /* BinarySearchTree_hpp */
