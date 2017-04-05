#include "BinarySearchTree.hpp"

std::ostream& operator<<(std::ostream& out, const BinarySearchTree& bst) {
    bst.print();
    return out;
}

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree::print() const {
    if (root != nullptr)
        root->print_nodes();
}

void BinarySearchTree::insert(int data) {
    TreeNode* new_node = new TreeNode;
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    if (root == nullptr)
        root = new_node;
    else
        root->insert_node(new_node);
}

int BinarySearchTree::count(int data) const {
    if (root == nullptr)
        return 0;
    else if (root->find(data))
        return 1;
    else
        return 0;
}

void BinarySearchTree::erase(int data) {
    TreeNode* to_be_removed = root;
    TreeNode* parent = nullptr;
    bool found = false;
    while (!found && to_be_removed != nullptr) {
        if (to_be_removed->data < data) {
            parent = to_be_removed;
            to_be_removed = to_be_removed->right;
        }
        else if (data < to_be_removed->data) {
            parent = to_be_removed;
            to_be_removed = to_be_removed->left;
        }
        else
            found = true;
    }
    
    if (!found)
        return;
    
    if (to_be_removed->left == nullptr || to_be_removed->right == nullptr) {
        TreeNode* children;
        if (to_be_removed->left == nullptr)
            children = to_be_removed->right;
        else
            children = to_be_removed->left;
        if (parent == nullptr)
            root = children;
        else if (parent->left == to_be_removed)
            parent->left = children;
        else
            parent->right = children;
        return;
    }
    TreeNode* smallest_parent = to_be_removed;
    TreeNode* smallest = to_be_removed->right;
    while (smallest->left != nullptr) {
        smallest_parent = smallest;
        smallest = smallest->left;
    }
    to_be_removed->data = smallest->data;
    if (smallest_parent == to_be_removed)
        smallest_parent->right = smallest->right;
    else
        smallest_parent->left = smallest->right;
}

int BinarySearchTree::smallest() const {
    TreeNode* parent = root;
    TreeNode* temp = parent;
    TreeNode* temp2 = root->left;
    while (parent->left != nullptr) {
        if (parent->data > temp2->data) {
            temp = temp2;
            parent = temp2;
        }
        temp2 = parent->left;
    }
    return temp->data;
}

int BinarySearchTree::largest() const {
    TreeNode* parent = root;
    TreeNode* temp = parent;
    TreeNode* temp2 = root->right;
    while (parent->right != nullptr) {
        if (parent->data < temp2->data) {
            temp = temp2;
            parent = temp2;
        }
        temp2 = parent->right;
    }
    return temp->data;
}

TreeIterator BinarySearchTree::begin() {
    TreeIterator iter;
    TreeNode* start;
    if (root->left == nullptr)
        iter.position = root;
    else {
        TreeNode* temp = root->left;
        while (temp->left != nullptr) {
            start = temp;
            temp = start->left;
        }
    }
    iter.position = start;
    iter.container = this;
    return iter;
}

TreeIterator BinarySearchTree::end() {
    TreeIterator iter;
    TreeNode* start;
    if (root->right == nullptr)
        iter.position = root;
    else {
        TreeNode* temp = root->right;
        while (temp->right != nullptr) {
            start = temp;
            temp = start->right;
        }
    }
    iter.position = start;
    iter.container = this;
    return iter;
}
