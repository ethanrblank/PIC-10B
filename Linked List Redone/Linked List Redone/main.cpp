#include <iostream>
#include "List.h"

void downsize(List&);
int maximum(List&);
//void sort(List&);


int main() {
    std::cout << "Please input a set of nonnegative numbers for a List (Enter -1 when you are finished): ";
    int input;
    std::cin >> input;
    List myList;
    while (input != -1) {
        myList.push_back(input);
        std::cout << "Please input a set of nonnegative numbers for a List (Enter -1 when you are finished): ";
        std::cin >> input;
    }
    
    std::cout << "Your list is" << std::endl;
    std::cout << "(";
    for (auto x : myList) {
        std::cout << x << ",";
    }
    std::cout << ")" << std::endl;
    
    int index = 0;
    int value = 0;
    std::cout << "Select an index for insertion (enter -1) when finished: ";
    std::cin >> index;
       while (index != -1) {
        std::cout << "Select a value for insertion: ";
        std::cin >> value;
        Iterator insert = myList.begin();
        insert+=index;
        myList.insert(insert, value);
        std::cout << "Select an index for insertion (enter -1) when finished: ";
        std::cin >> index;
    }
    
    std::cout << "The augmented List is" << std::endl;
    std::cout << "(";
    for (auto x : myList) {
        std::cout << x << ",";
    }
    std::cout << ")" << std::endl;
    
    std::cout << "The maximum of the List is: " << maximum(myList) << std::endl;
    std::cout << "The size of the List is: " << myList.get_size() << std::endl;
    std::cout << "When we remove every second value from this list we are left with" << std::endl;
    downsize(myList);
    std::cout << "(";
    for (auto x : myList) {
        std::cout << x << ",";
    }
    std::cout << ")" << std::endl;
    std::cout << "And this sorted list in reverse order is" << std::endl;
    myList.reverse();
    std::cout << "(";
    for (auto x : myList) {
        std::cout << x << ",";
    }
    std::cout << ")" << std::endl;
    std::cout << "If we merge this list with the list (2,3,5,7,11) we obtain" << std::endl;
    List second;
    second.push_back(2); second.push_back(3); second.push_back(5); second.push_back(7); second.push_back(11);
    myList.merge(second);
    
    std::cout << "(";
    for (auto x : myList) {
        std::cout << x << ",";
    }
    std::cout << ")";
    return 0;
}

void downsize(List& other) {
    int interval = 1;
    
    for (Iterator begin = other.begin(), end = other.end(); begin != end; ++begin) {
        if (!(interval%2))
            other.erase(begin);
        ++interval;
    }
}

int maximum (List& this_list) { // need to const begin and end functions
    Iterator first = this_list.begin();
    int max = *first;
    
    for (Iterator begin = this_list.begin(), end = this_list.end(); begin!=end; ++begin) {
        if (max < *begin)
            max = *begin;
    }
    
    return max;
}

//void sort(List& this_list) {
//    for (Iterator start = this_list.begin(), stop = this_list.end(); start != stop; ++start) {
//        
//    }
//}
