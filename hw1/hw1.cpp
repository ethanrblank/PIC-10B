/** @file hw1.cpp
 @author [Ethan Blank]
 @date [9/30/16]
 
 [This program takes two user inputed values and converts an unsigned int to a class called "Integer". This class then takes the value that the user inputs and converts it to bits. The class can also add and multiply the Integers. The Integer class contains a private variable, value, and a vector of booleans, which consists of 1's and 0's, which is used to display the number in binary.]
 
 */

#include <iostream>
#include <vector>


/** @class Integer
 @brief Stores an integer value using bits
 
 This class is designed to mimic the int data type. It consists of a 10-number system value and a vector of booleans of which it stores the number in binary.
 
 */
class Integer {
public:
    Integer();
    Integer(unsigned int a);
    
    void plus_equals(const Integer& rhs);
    void times_equals(const Integer& rhs);
    unsigned int get_value(Integer &a) const; // used later to reassign binary numbers to Integers that previously exist (converting A & B to C & D)
    void print_as_int() const;
    void print_as_bits() const;
    
private:
    unsigned int value; // the true 10-number value of any given number
    std::vector<bool> bit;
    
    void clean_up();
};

// Member functions defined below.

Integer::Integer() {
    value = 0;
    bit.push_back(0);
}

Integer::Integer(unsigned int a) {
    value = a;
    int initial = a;
    if (initial == 0) {
        bit.push_back(0);
    }
    else {
        while (initial > 0) {
            bit.push_back(initial%2);
            initial /= 2;
        }
    }
}

void Integer::print_as_int() const{
    std::cout << value;
}

unsigned int Integer::get_value(Integer &a) const {
    return a.value;
}

void Integer::print_as_bits() const {
    std::cout << "(";
    for (int i = (bit.size()-1); i >= 0; --i) {
        std::cout << bit[i];
    }
    std::cout << ")_2";
}

void Integer::plus_equals(const Integer &rhs) {
    value += rhs.value;
}

void Integer::times_equals(const Integer &rhs) {
    value *= rhs.value;
}

Integer plus(Integer lhs, const Integer& rhs) {
    lhs.plus_equals(rhs);
    unsigned int plus_value = lhs.get_value(lhs);
    Integer plus_result = plus_value; // I needed to create new Integers so that the bit vector could re-initialize
    return plus_result;
}
Integer multiply(Integer lhs, const Integer& rhs) {
    lhs.times_equals(rhs);
    unsigned int multiply_value = lhs.get_value(lhs);
    Integer multiply_result = multiply_value;
    return multiply_result;
}

int main(int argc, const char * argv[]) {
    
    unsigned int uint_value;
    
    std::cout << "Please input an integer a: ";
    std::cin >> uint_value;
    Integer a = uint_value; // Create Integer type with input value
    
    std::cout << "The base-2 representation of a is: "; a.print_as_bits(); std::cout << std::endl;
    
    std::cout << "Please input an integer b: ";
    std::cin >> uint_value;
    Integer b = uint_value; // Create Integer type with input value
    
    std::cout << "The base-2 representation of b is: "; b.print_as_bits(); std::cout << std::endl;
    
    Integer c = plus(a,b);      // a + b
    Integer d = multiply(a,b);  // a * b
    
    std::cout << "a + b = "; c.print_as_int(); std::cout <<" = "; c.print_as_bits();std::cout << std::endl;
    std::cout << "a * b = "; d.print_as_int(); std::cout <<" = "; d.print_as_bits();std::cout << std::endl;
    
    a.plus_equals(b);
    std::cout << "After a += b, a = "; a.print_as_int();std::cout << std::endl;
    
    Integer two = 2;
    b.times_equals(two);
    std::cout << "After b *= 2, b = "; b.print_as_int();std::cout << std::endl;
    
    
    return 0;
}
