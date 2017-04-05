/** @file hw9.cpp
 @author [Ethan Blank]
 @date [11/29/16]
 
 [This program creates a binary search tree and performs several operationson it. It utilizes created classes called BinarySearchTree, TreeNode, and TreeIterator. It erases nodes on the tree, finds a value on the tree, and prints the objects within the tree.]
 
 */

#include "BinarySearchTree.hpp"

int main() {
    BinarySearchTree bst;
    bst.insert(3); bst.insert(2); bst.insert(11); bst.insert(13); bst.insert(5); bst.insert(17);
    
    for (auto x: bst) std::cout << x << ",";
    std::cout << std::endl;
    bst.erase(6);
    bst.erase(11);
    
    auto start = std::begin(bst);
    auto stop = std::end(bst);
    
    int value = 17;
    bool keep_looking = true;
    while(start != stop && keep_looking)
        if(*start++==value) keep_looking = false ;
    --start;
    
    if (start !=stop)
        std::cout << *start << "is in the list." << std:: endl;
    return 0;
}
