/** ... */

#include <iostream>
#include "Integer.hpp"

int main() {
    int uint_value;
    std::cout << "Please input an integer a: ";
    std::cin >> uint_value;
    Integer a = uint_value;
    
    std::cout << "The base-2 representation of a is: " << a << std::endl;
    
    std::cout << "Please input an integer b: ";
    std::cin >> uint_value;
    Integer b = uint_value;
    
    std::cout << "The base-2 representation of b is: " << b << std::endl;
    
    Integer c = a+b;
    Integer d = a*b;
    
    std::cout << "a + b = "; c.print_as_int(); std::cout << " = " << c << std::endl;
    std::cout << "a * b = "; d.print_as_int(); std::cout << " = " << d << std::endl;
    
    if (a<b) std::cout << "a < b" << std::endl;
    if (a<=b) std::cout << "a <= b" << std::endl;
    if (a == b) std::cout << "a == b" << std::endl;
    if (a != b) std::cout << "a != b" << std::endl;
    if (a >= b) std::cout << "a >= b" << std::endl;
    if (a > b) std::cout << "a > b" << std::endl;
    
    return 0;
}

