#include <iostream>
#include "InputFile.h"
#include "OutputFile.h"

/** @file hw6.cpp
 @author [Ethan Blank]
 @date [11/4/16]
 
 [This program utilizes a class, OutputFile, and a class, InputFile, which both mimic similar functionality to cout << and cin >> but instead writes and reads from external files. The program contains several recursive functions to computer partitions, Stirling numbers, and factorials of a user designated integer, then prints the results of those functions to separate files.]
 
 */

/** Function Declarations **/

int factorial(int n);
int p(int k, int n);
int n(int k, int n);
int S(int k, int n);
void function(int m, std::string filename);

int main() {
    std::cout << "Welcome! Please inpute a number m: ";
    int m;
    std::cin >> m;
    std::cout << "Creating Partition.txt file ... ";
    function(m, "Partition.txt");
    std::cout << "Creating Stirling1.txt file ... ";
    function(m, "Stirling1.txt");
    std::cout << "Creating Stirling2.txt file ... ";
    function(m, "Stirling2.txt");
    std::cout << "Creating Factorials.txt file ... ";
    function(m, "Factorials.txt");
    return 0;
}

/** Function Definitions **/

/**
 @param int n
 
 @return n * factorial(n-1) for any other number n but 1
 
 Recursive factorial function computes the factorial of any integer greater than 0. Utilizes 1! as the base computation to compute larger factorials.
**/

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    else
        return n * factorial(n-1);
}

/**
 @param k
 @param n
 
 @return p(k,n-k) +p(k-1,n)
 
 This recursive function computes the partitions of any given integer number from 1-n. The if and if else statements designate base cases which the else statement will use for computations.
 
 **/

int p(int k, int n) {
    if (k < 0 || n < 0)
        return 0;
    else if (k == 0 && n > 0)
        return 0;
    else if (k >= 0 && n == 0)
        return 1;
    else if (k > n)
        return p(n,n);
    else
        return p(k, n-k) + p(k-1,n);
}

/**
 @param k
 @param n
 
 @return -(n-1)*s(k,n-1)+s(k-1,n-1)
 
 This recursive function computes the partitions of any given integer number from 1-n. The if and if else statements designate base cases which the else statement will use for computations.
 **/

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
        return -(n-1)*s(k,n-1)+s(k-1,n-1);
}

/**
 @param k
 @param n
 
 @return k*S(k,n-1) + S(k-1, n-1)
 
  This recursive function computes the partitions of any given integer number from 1-n. The if and if else statements designate base cases which the else statement will use for computations.
 **/

int S(int k, int n) {
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
        return k*S(k, n-1) + S(k-1, n-1);
}

/**
 @param m
 @param filename
 
 This function allows me to easily output several functions to files of differing names.

 **/

void function(int m, std::string filename) {
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
                        fout << S(k,n) << " ";
                }
            }
            // prints a new line to the designated file so that numbers are separated
            fout << "\n";
        }

}
