/** @file hw7.cpp
 @author [Ethan Blank]
 @date [11/11/16]
 
 [This program utilizes a class called Point2D with two derived classes, ColorPoint2D and WeightedPoint2D that creates (x,y) points of various types (normal, weighted, color). The user is asked to input what kind of points he or she would like to create. The points that the user created are stored as Point2D pointers on the heap in a vector within a Points object. The points are sorted and then the program prints the those points to the console.]
 
 */

#include <iostream>
#include "Point2D.h"
#include "ColorPoint2D.h"
#include "WeightedPoint2D.h"
#include "Points.h"


int main() {
    
    std::cout << "Welcome to Point Printer! You can create three different kinds of points:\n\n";
    std::cout << "1. Point2D, e.g., (2,6.5)" << std::endl << "2. ColorPoint2D, e.g., blue(-4.5,3.5)" << std::endl << "3. WeightedPoint2D, e.g., .12(3.6,8.7)\n\n";
    
    std::cout << "Enter 0 when you are finished.\n\n";
    
    Points p;
    int selection = -1; // initialized at negative 1 so the loop can run
    double x, y, weight;
    std::string color; // color variable to define a color point
    while (selection != 0) {
        std::cout << "Selection: "; // asks user to input a selection for the type of point to create
        std::cin >> selection;
        if (selection == 0)
            break;
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        switch (selection) { // switch statement for creating various points
            default:
                break;
            case 1: {
                Point2D* regularPoint = new Point2D(x,y);
                p.push_back(regularPoint);
                break;
            }
            case 2: {
                std::cout << "color = ";
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, color);
                Point2D* colorPoint = new ColorPoint2D(x, y, color);
                p.push_back(colorPoint);
                break;
            }
            case 3: {
                std::cout << "weight = ";
                std::cin >> weight;
                Point2D* weightPoint = new WeightedPoint2D(x,y, weight);
                p.push_back(weightPoint);
                break;
            }
        }
    }
    std::cout << std::endl;

    std::cout << "Your sorted points are\n";
    p.sort(); // Vector is sorted
    p.print(); // Vector is printed
    return 0;
}

