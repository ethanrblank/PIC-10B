//
//  Integer.hpp
//  Integer Class Redone
//
//  Created by Ethan Blank on 12/11/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#ifndef Integer_hpp
#define Integer_hpp

#include <iostream>
#include <vector>
#include <cmath>


class Integer {
    friend std::ostream& operator<<(std::ostream& out, const Integer& output);
public:
    Integer();
    Integer(int a);
    Integer& operator+=(const Integer& rhs);
    Integer& operator*=(const Integer& rhs);
    Integer& operator-=(const Integer& rhs);
    Integer& operator++();
    Integer& operator<<=(unsigned int);
    bool operator==(const Integer& rhs) const;
    bool operator<(const Integer& rhs) const;
    void print_as_int() const;
private:
    std::vector<bool> bit;
    bool sign;
    inline void clean_up() {
        size_t i = bit.size()-1;
        while (bit[i] == 0 && i != 0) {
            bit.pop_back();
            --i;
        }
    }
    inline size_t smaller_bit_size(const Integer& a, const Integer& b) const {
        if (a.bit.size() > b.bit.size())
            return b.bit.size();
        else
            return a.bit.size();
    }
    inline size_t larger_bit_size(const Integer& a, const Integer& b) const {
        if (a.bit.size() > b.bit.size())
            return a.bit.size();
        else
            return b.bit.size();
    }
};

Integer operator+(Integer lhs, const Integer& rhs);
Integer operator*(Integer lhs, const Integer& rhs);
Integer operator<<(Integer a, unsigned int shift);
Integer operator++(const Integer& a, int unused);
bool operator!=(const Integer& lhs, const Integer& rhs);
bool operator>(const Integer& lhs, const Integer& rhs);
bool operator<=(const Integer& lhs, const Integer& rhs);
bool operator>=(const Integer& lhs, const Integer& rhs);

#endif /* Integer_hpp */
