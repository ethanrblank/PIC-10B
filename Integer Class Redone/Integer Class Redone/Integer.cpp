
#include "Integer.hpp"

std::ostream& operator<<(std::ostream& out, const Integer& output) {
    if (output.sign) {
        out << "-";
    }
    out << "(";
    for (int i = (int)output.bit.size()-1; i >= 0; --i) {
        out << output.bit[i];
    }
    out << ")_2";
    return out;
}

Integer::Integer() {
    bit.push_back(0);
    sign = false;
}

Integer::Integer (int a) {
    int initial;
    if (a < 0) {
        sign = true;
        initial = -a;
    }
    else {
        sign = false;
        initial = a;
    }
    
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

Integer& Integer::operator+=(const Integer& rhs) {
    std::vector<bool> carry {0};
    for (size_t i = 0, p = smaller_bit_size((*this), rhs); i < p; ++i) {
        if (carry[i] == 0) {
            if (bit[i] == 0) {
                if (rhs.bit[i] == 0) {
                    bit[i] = 0;
                    carry.push_back(0);
                }
                else if (rhs.bit[i] == 1) {
                    bit[i] = 1;
                    carry.push_back(0);
                }
            }
            else if (bit[i] == 1) {
                if (rhs.bit[i] == 0) {
                    carry.push_back(0);
                    bit[i] = 1;
                }
                else if (rhs.bit[i] == 1) {
                    carry.push_back(1);
                    bit[i] = 0;
                }
            }
        }
        else if (carry[i] == 1) {
            if (bit[i] == 0) {
                if (rhs.bit[i] == 0) {
                    carry.push_back(0);
                    bit[i] = 1;
                }
                else if (rhs.bit[i] == 1) {
                    carry.push_back(1);
                    bit[i] = 0;
                }
            }
            else if (bit[i] == 1) {
                if (rhs.bit[i] == 0) {
                    carry.push_back(1);
                    bit[i] = 0;
                }
                else if (rhs.bit[i] == 1) {
                    carry.push_back(1);
                    bit[i] = 1;
                }
            }
        }
    }
    
    if (bit.size() != rhs.bit.size()) {
        if (bit.size() > rhs.bit.size()){
            for (size_t i = smaller_bit_size((*this), rhs), p = larger_bit_size((*this), rhs); i < p; ++i) {
                if (carry[i] == 0) {
                    if (bit[i] == 0) {
                        carry.push_back(0);
                        bit[i] = 0;
                    }
                    else if (bit[i] == 1) {
                        carry.push_back(0);
                        bit[i] = 1;
                    }
                }
                else if (carry[i] == 1) {
                    if (bit[i] == 0) {
                        carry.push_back(0);
                        bit[i] = 1;
                    }
                    else if (bit[i] == 1) {
                        carry.push_back(1);
                        bit[i] = 0;
                    }
                }
            }
        }
        else if (bit.size() < rhs.bit.size()) {
            for (size_t i = smaller_bit_size((*this), rhs), p = larger_bit_size((*this), rhs); i < p; ++i) {
                if (carry[i] == 0) {
                    if (rhs.bit[i] == 0) {
                        carry.push_back(0);
                        bit.push_back(0);
                    }
                    else if (rhs.bit[i] == 1) {
                        carry.push_back(0);
                        bit.push_back(1);
                    }
                }
                else if (carry[i] == 1) {
                    if (rhs.bit[i] == 0) {
                        carry.push_back(0);
                        bit.push_back(1);
                    }
                    else if (rhs.bit[i] == 1) {
                        carry.push_back(1);
                        bit.push_back(0);
                    }
                }
            }
        }
    }
    for (size_t i = bit.size(), p = carry.size(); i<p; ++i) {
        bit.push_back(carry[i]);
    }
    this->clean_up();
    return *this;
}

Integer& Integer::operator-=(const Integer& rhs) {
    if (this->sign != rhs.sign) { // if the signs differ i.e. 100 - -2 or -100 - +2 then just add the two numbers, the sign follows the sign of [this]
        *this += rhs;
        return *this;
    }
    
    else {
        if (sign == true) {
            for (size_t i = 0, p = bit.size(); i < p; ++i) {
                if (bit[i] == false)
                    bit[i] = true;
                else
                    bit[i] = false;
            }
            *this += 1; // now it is fully converted into two's complement
            
            *this += rhs;
            
        }
    }
}

Integer& Integer::operator<<=(unsigned int val) {
    while (val != 0) {
        bit.push_back(0);
        for (size_t i = bit.size()-1, p = 0; i > p; --i) {
            bit[i] = bit[i-1];
        }
        bit[0] = 0;
        --val;
    }
    return *this;
}

Integer& Integer::operator*=(const Integer& rhs) {
    if ((rhs.bit.size() == 1 && rhs.bit[0] == 0) || (bit.size() == 1 && bit[0] == 0)) {
        return *this = 0;
    }
    
    Integer a = *this;
    Integer b = *this;
    for (size_t i = 0, p = rhs.bit.size(); i < p; ++i) {
        if (i == 0) {
            if (rhs.bit[i] == 0)
                *this = 0;
        }
        else {
            a = b<<(unsigned int)i;
            if (rhs.bit[i] == 1)
                (*this) += a;
        }
    }
    return *this;
}

Integer& Integer::operator++() {
    return (*this) += 1;
}

bool Integer::operator==(const Integer& rhs) const {
    if (bit.size() != rhs.bit.size())
        return false;
    else {
        if (bit[bit.size()-1] != rhs.bit[rhs.bit.size()-1])
            return false;
        else {
            for (size_t i = 0, p = bit.size(); i < p; ++i) {
                if (bit[i] != rhs.bit[i])
                    return false;
            }
        }
    }
    return true;
}

bool Integer::operator<(const Integer& rhs) const {
    if (bit.size() < rhs.bit.size())
        return true;
    else if (bit.size() > rhs.bit.size())
        return false;
    else {
        for (size_t i = 0, p = bit.size(); i < p; ++i) {
            if (bit[i] < rhs.bit[i])
                return true;
        }
    }
    return false;
}

void Integer::print_as_int() const {
    unsigned int value = 0;
    for (size_t i = 0, p = bit.size(); i < p; ++i) {
        if (bit[i] == 1) {
            value += pow(2,i);
        }
    }
    std::cout << value;
}

Integer operator<<(Integer a, unsigned int shift) {
    return a<<=shift;
}

Integer operator+(Integer lhs, const Integer& rhs) {
    return lhs+=rhs;
}

Integer operator*(Integer lhs, const Integer& rhs) {
    return lhs*=rhs;
}

bool operator>(const Integer& lhs, const Integer& rhs) {
    return rhs<lhs;
}

bool operator!=(const Integer& lhs, const Integer& rhs) {
    return !(lhs==rhs);
}

bool operator<=(const Integer& lhs, const Integer& rhs) {
    return !(lhs>rhs);
}

bool operator>=(const Integer& lhs, const Integer& rhs) {
    return !(lhs < rhs);
}



