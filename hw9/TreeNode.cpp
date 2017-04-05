

#include "TreeNode.hpp"

void TreeNode::insert_node(TreeNode *new_node) {
    if (new_node->data < data) {
        if (left == nullptr)
            left = new_node;
        else
            left->insert_node(new_node);
    }
    else if (data < new_node->data) {
        if (right == nullptr)
            right = new_node;
        else
            right->insert_node(new_node);
    }
}

bool TreeNode::find(int value) const {
    if (value < data) {
        if (left == nullptr)
            return false;
        else
            return left->find(value);
    }
    else if (data < value) {
        if (right == nullptr)
            return false;
        else
            return right->find(value);
    }
    else
        return true;
}

void TreeNode::print_nodes() const {
    if (left != nullptr)
        left->print_nodes();
    std::cout << data << "\n";
    if (right != nullptr)
        right->print_nodes();
}
