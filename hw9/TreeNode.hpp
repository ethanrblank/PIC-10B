//@class TreeNode used to create nodes within the BinarySearchTree. Has private variables left and right, and a data variable which stores an int.

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <iostream>

class TreeNode {
public:
    void insert_node(TreeNode* new_node);
    void print_nodes() const;
    bool find(int value) const;
private:
    int data;
    TreeNode* left;
    TreeNode* right;
    friend class BinarySearchTree;
    friend class TreeIterator;
};

#endif /* TreeNode_hpp */
