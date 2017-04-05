/** @file hw2.cpp
 @author [Ethan Blank]
 @date [10/7/16]
 
 [This program takes two user inputed values and converts an unsigned int to a class called "Integer". This class then takes the value that the user inputs and converts it to bits. The class can also add and multiply the Integers. The Integer class contains a private variable, value, and a vector of booleans, which consists of 1's and 0's, which is used to display the number in binary.]
 
 */

#include <iostream>
#include <vector>

/** @class Integer
 @brief Stores an integer value using bits
 
 This class is designed to mimic the int data type. It consists of a 10-number system value and a vector of booleans of which it stores the number in binary.
 
**/

class Integer {
public:
    Integer();
    Integer(unsigned int a);
    Integer& operator +=(const Integer& value);
    Integer& operator <<=(unsigned int shift);
    Integer& operator *=(const Integer& value);
    bool operator <(const Integer& comparison) const;
    bool operator ==(const Integer& comparison) const;
    unsigned int get_number() const;
    void print_as_int() const;
    void print_as_bits() const;
    
private:
    std::vector<bool> bit;
    void clean_up();
};

// End class declaration

Integer::Integer() {
    bit.push_back(0);
}

// Default constructor

Integer::Integer(unsigned int a) {
    unsigned int initial = a;
    if (initial == 0) {
        bit.push_back(0);
    }
    else {
        while (initial > 0) {
            bit.push_back(initial%2);
            initial/= 2;
        }
    }
}

// Constructor for Integer class that allows for user specified values.

void Integer::clean_up(){
    int bitSize = (int)bit.size();
    
    if (bitSize != 1) {
        int i = bitSize - 1;
        while (bit[i] != true) {
            bit.pop_back();
            --i;
        }
    }
}

// Cleans the extraneous zeros at the front of the binary number.

bool Integer::operator <(const Integer &comparison) const {
    if (bit.size() < comparison.bit.size())
        return true;
    if (bit.size() == comparison.bit.size()) {
        for (int i = (int)bit.size(); i >= 0; --i) {
            if (bit[i] < comparison.bit[i]) {
                return true;
            }
        }
    }
    return false;
}

// Overloaded the comaprison operator so that by first size of the binary number. If the numbers are the same size then the first binary that contains a zero is the smallest.

bool Integer::operator ==(const Integer& comparison) const {
    if (bit.size() != comparison.bit.size())
        return false;
    if (bit.size() == comparison.bit.size()) {
        for (int i = (int)bit.size(); i >= 0; --i) {
            if (bit[i] != comparison.bit[i])
                return false;
        }
    }
    return true;
    
}

// If the binary numbers are not the same size, then they are not equal. If they are equal then it compares the vectors one-by-one to determine if each element is equal.

bool operator!= (const Integer& lhs, const Integer& rhs) {
    return !(lhs == rhs);
}
bool operator>  (const Integer& lhs, const Integer& rhs){
    return rhs < lhs;
}
bool operator<=(const Integer& lhs, const Integer& rhs) {
    return !(lhs > rhs);
}
bool operator>=(const Integer& lhs, const Integer& rhs) {
    return !(lhs < rhs);
}

// secondary overloaded operators


Integer& Integer::operator +=(const Integer& value) {
    
    std::vector<bool> carryOvers(1);
    
    carryOvers[0] = false;
    
    size_t sizeA = bit.size();
    size_t sizeB = value.bit.size();
    
    if (sizeA >= sizeB) {
        for (size_t i = 0; i < sizeB; ++i) {
            bool a = bit[i];
            bool b = value.bit[i];
            bool c = carryOvers[i];
            
            if (!(a^b)) {
                if (c == 1) {
                    if (!(a&b)) {
                        bit[i] = 1;
                        carryOvers.push_back(0);
                    }
                    else if (a&b) {
                        bit[i] = 1;
                        carryOvers.push_back(1);
                    }
                }
                else if (c != 1) {
                    if (!(a&b)) {
                        bit[i] = 0;
                        carryOvers.push_back(0);
                    }
                    else if (a&b) {
                        bit[i] = 0;
                        carryOvers.push_back(1);
                    }
                }
            } // END if(!(a^b))
            else if (a^b) {
                if (c == 1) {
                    bit[i] = 0;
                    carryOvers.push_back(1);
                }
                else if (c != 1) {
                    bit[i] = 1;
                    carryOvers.push_back(0);
                }
            } // END else if (a^b)
        } // END FOR LOOP
       
        size_t sizeCarry = carryOvers.size();
        
        {
        // CLEAN UP CARRYOVERS
            size_t i = sizeCarry-1;
            while (carryOvers[i] != true) {
                carryOvers.pop_back();
                --i;
            } // END CLEANING WHILE LOOP
        }
            
        if (sizeA == sizeB) {
            if (sizeA < sizeCarry) {
                for (size_t i = sizeA; i < sizeCarry; ++i) {
                    bit.push_back(carryOvers[i]);
                }
            }
            this->clean_up();
            return *this;
        } // END if (sizeA == sizeB)

        if (sizeA > sizeB) {
            for (size_t i = sizeB; i < sizeA; ++i) {
                bool a = bit[i];
                bool c = carryOvers[i];
                
                if (!(a^c)) {
                    if (!(a&c)) {
                        this->clean_up();
                        return *this;
                    }
                    else if (a&c) {
                        bit[i] = 0;
                        carryOvers.push_back(1);
                    }
                } // END if (!(a^c))
                else if (a^c) {
                    bit[i] = 1;
                    carryOvers.push_back(0);
                } // END if (a^c)
            } // END for loop
        } // END if (sizeA > sizeB)
        
        {
            // CLEAN UP CARRYOVERS
            size_t i = sizeCarry-1;
            while (carryOvers[i] != true) {
                carryOvers.pop_back();
                --i;
            } // END CLEANING WHILE LOOP
        }
        sizeCarry = carryOvers.size();
        
        if (sizeA < sizeCarry) {
            for (size_t i = sizeA; i < sizeCarry; ++i) {
                bit.push_back(carryOvers[i]);
            }
        } // END if (sizeA > sizeCarry)
    }
    
    if (sizeA < sizeB) {
        Integer copiedValue = value;
        size_t newSizeA = copiedValue.bit.size();
        size_t newSizeB = bit.size();
        for (size_t i = 0; i < newSizeB; ++i) {
            bool a = copiedValue.bit[i];
            bool b = bit[i];
            bool c = carryOvers[i];
            
            if (!(a^b)) {
                if (c == 1) {
                    if (!(a&b)) {
                        copiedValue.bit[i] = 1;
                        carryOvers.push_back(0);
                    }
                    else if (a&b) {
                        copiedValue.bit[i] = 1;
                        carryOvers.push_back(1);
                    }
                }
                else if (c != 1) {
                    if (!(a&b)) {
                        copiedValue.bit[i] = 0;
                        carryOvers.push_back(0);
                    }
                    else if (a&b) {
                        copiedValue.bit[i] = 0;
                        carryOvers.push_back(1);
                    }
                }
            } // END if(!(a^b))
            else if (a^b) {
                if (c == 1) {
                    copiedValue.bit[i] = 0;
                    carryOvers.push_back(1);
                }
                else if (c != 1) {
                    copiedValue.bit[i] = 1;
                    carryOvers.push_back(0);
                }
            } // END else if (a^b)
        } // END FOR LOOP
        
        size_t sizeCarry = carryOvers.size();
        
        {
            // CLEAN UP CARRYOVERS
            size_t i = sizeCarry-1;
            while (carryOvers[i] != true && i !=0) {
                carryOvers.pop_back();
                --i;
            } // END CLEANING WHILE LOOP
        }
        for (size_t i = newSizeB; i < newSizeA; ++i) {
            bool a = copiedValue.bit[i];
            bool c = carryOvers[i];
            
            if (!(a^c)) {
                if (!(a&c)) {
                    this->clean_up();
                    return *this;
                }
                else if (a&c) {
                    copiedValue.bit[i] = 0;
                    carryOvers.push_back(1);
                }
            } // END if (!(a^c))
            else if (a^c) {
                copiedValue.bit[i] = 1;
                carryOvers.push_back(0);
            } // END if (a^c)
        } // END for loop
        
        bit = copiedValue.bit;
    }
    
    this->clean_up();
    return *this;
}

// An algorithim for overloading the += operator. I created a carryover vector for extra 1's that need to be carried over through addition. The algorithim compares the two main vectors and then the carry-over vector and adheres to addition rules.

Integer operator +(Integer a, const Integer& b) {
    return a+=b;
}

// Utilizes the += operator to define the simple + operator.

Integer& Integer::operator<<=(unsigned int shift) {
    for (int i = 0; i < shift; ++i) {
        bit.push_back(0);
    }
    for (size_t i = bit.size()-1, n = 0; i > n; --i) {
        bit[i] = bit[i-1];
    }
    bit[0] = 0;
    return *this;
}

Integer& Integer::operator*=(const Integer& value) {
    Integer A = *this;
    for (size_t i = 0, n = value.bit.size(); i < n; ++i) {
        if (value.bit[i] == 1 && i != 0) {
            A <<= 1;
            *this += A;
        }
        
        else if (value.bit[i] == 0 && i != 0) {
            A <<= 1;
        }
    }
    return *this;
}

// I utilized the += operator to construct the *= operator. For instance, if we multiply 9*3 it is the same as doing 9+9+9, which is the algorithim I used to define this operator.

Integer operator *(Integer a, const Integer& b) {
    return a*=b;
}
// utilized the *= operator to define the simple * operator

void Integer::print_as_bits() const {
    std::cout << "(";
    for (int i = (int)bit.size()-1; i >= 0; --i) {
        std::cout << bit[i];
    }
    std::cout << ")_2";
}
// traverses through the vector and prints to the screen.

void Integer::print_as_int() const {
    //std::cout << number;
}

// Prints the value by accessing the unsigned int private variable.

int main() {
    
    unsigned int uint_value ;
    std::cout << "Please input an integer a: ";
    std :: cin >> uint_value ;
    Integer a = uint_value; // Create Integer type with input value
    std::cout << "The base−2 representation of a is: ";
    a.print_as_bits();
    std::cout << std::endl;
    std::cout << "Please input an integer b: ";
    std :: cin >> uint_value ;
    Integer b = uint_value; // Create Integer type with input value
    std::cout << "The base−2 representation of b is: "; b.print_as_bits();
    std::cout << std::endl;
    // Let ' s do some basic arithmetic Integer c = a+b;
    Integer c = a+b;
    Integer d = a*b;
    // Print out values
    std::cout << "a + b = "; c.print_as_int(); std::cout << " = "; c.print_as_bits () ; std::cout << std::endl ;
    std::cout << "a ∗ b = "; d.print_as_int(); std::cout << " = "; d.print_as_bits () ; std::cout << std::endl ;
    // Test comparison functions
    if(a < b) std::cout << "a < b" << std::endl;
    if(a <= b) std::cout << "a <= b" << std::endl;
    if(a == b) std::cout << "a == b" << std::endl;
    if(a != b) std::cout << "a != b" << std::endl;
    if(a >= b) std::cout << "a >= b" << std::endl;
    if(a > b) std::cout << "a > b" << std::endl;
    return 0;
}
