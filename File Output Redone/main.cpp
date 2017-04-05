//
//  main.cpp
//  File Output Redone
//
//  Created by Ethan Blank on 12/21/16.
//  Copyright © 2016 Ethan Blank. All rights reserved.
//

#include <iostream>
#include "File.h"

void function_controller(const int, const std::string);
int p(int, int);
int s(int, int);
int s_two(int, int);
int factorial(int);

int main () {
    std::cout << "Welcome! Please input a number m: ";
    int m;
    std::cin >> m;
    
    std::cout << "Creating Partition.txt file ... ";
    function_controller(m, "Partition.txt");
    
    std::cout << "Creating Stirling1.txt file ... ";
    function_controller(m, "Stirling1.txt");
    
    std::cout << "Creating Stirling2.txt file ... ";
    function_controller(m, "Stirling2.txt");
    
    std::cout << "Creating Factorials.txt file ... ";
    function_controller(m, "Factorials.txt");
    return 0;
}

void function_controller(const int m, const std::string filename) {
    OutputFile fout(filename); // I utilize my OutputFile class to create the fout object will be used simulate cout << but to print to the file.
    for (int k = 1; k < m+1; ++k) {
        if (filename == "Factorials.txt") {
            fout << factorial(k);
        }
        else {
            for (int n = 1; n < m+1; ++n) {
                // Several if statements to control the path of the compiler depending on which file is being created.
                if (filename == "Partition.txt")
                    fout << p(k, n) << " ";
                else if (filename == "Stirling1.txt")
                    fout << s(k, n) << " ";
                else if (filename == "Stirling2.txt")
                    fout << s_two(k,n) << " ";
            }
        }
        // prints a new line to the designated file so that numbers are separated
        fout << "\n";
    }
    
}

int p(int k, int n) {
    if (k < 0 || n < 0)
        return 0;
    else if (k == 0 && n > 0) // p(0,n)
        return 0;
    else if (k >= 0 && n == 0) // p(+k,0)
        return 1;
    else if (k > n) // p(-1,-2)
        return p(n,n);
    else
        return p(k, n-k) + p(k-1, n);
}

int s(int k, int n) {
    if (k < 0 || n < 0)
        return 0;
    else if (k == 0 && n > 0)
        return 0;
    else if (k > 0 && n == 0)
        return 0;
    else if (k > n)
        return 0;
    else if (k == n)
        return 1;
    else
        return -(n-1)*s(k,n-1) + s(k-1,n-1);
}

int s_two(int k, int n) {
    if (k < 0 || n < 0)
        return 0;
    else if (k == 0 && n > 0)
        return 0;
    else if (k > 0 && n == 0)
        return 0;
    else if (k > n)
        return 0;
    else if (k == n)
        return 1;
    else
        return k*s_two(k, n-1) + s_two(k-1, n-1);
}

int factorial(int m) {
    if (m == 1)
        return 1;
    else
        return m * factorial(m-1);
}

