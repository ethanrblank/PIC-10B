/** @file main.cpp
    @author [Ethan Blank]
    @date [12/20/16]
    
    @brief Utilizes the Point2D classes (plus inherited classes) and the Points class to create and store points. Then prints those points to the console.
 */

#include <iostream>
#include "Point2D.h"
#include "Points.h"


int main() {
    std::cout << "Welcome to Point Printer! You can create three different kinds of points: " << std::endl;
    std::cout << "1. Point2D, e.g., (2, 6.5)" << std::endl << "2. ColorPoint2D, e.g., blue(-4.5, 3.5)" << std::endl << "3. WeightedPoint2D, e.g., .12(3.6, 8.7)" << std::endl;
    
    std::cout << "Enter 0 when you are finished." << std::endl;
    
    int selection = 0;
    std::cout << "Selection: ";
    std::cin >> selection;
    
    while (std::cin.fail()) {
        std::cin.clear(); std::cin.ignore();
        std::cout << "Selection: ";
        std::cin >> selection;
    }
    
    Points collection;
    
    while (selection != 0) {
        double x = 0;
        double y = 0;
       
        std::cout << "x = ";
        std::cin >> x;
        
        while (std::cin.fail()) {
            std::cin.clear();
            std::cout << "x = ";
            std::cin >> x;
        }
        
        std::cout << "y = ";
        std::cin >> y;
        
        while (std::cin.fail()) {
            std::cin.clear();
            std::cout << "y = ";
            std::cin >> y;
        }
        
        switch (selection) {
            case 1: {
                Point2D* a = new Point2D(x,y);
                collection.push_back(a);
                break;
            }
            case 2: {
                std::cout << "color = ";
                std::string color;
                std::cin.ignore();
                getline(std::cin, color);
                Point2D* b = new ColorPoint2D(x,y,color);
                collection.push_back(b);
                break;
            }
            case 3: {
                std::cout << "weight = ";
                double weight;
                std::cin >> weight;
                
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cout << "weight = ";
                    std::cin >> weight;
                }
                
                Point2D* c = new WeightedPoint2D(x,y,weight);
                collection.push_back(c);
                break;
            }
            default:
                break;
        }
        std::cout << "Selection: ";
        std::cin >> selection;
        while (std::cin.fail()) {
            std::cin.clear(); std::cin.ignore();
            std::cout << "Selection: ";
            std::cin >> selection;
        }
    }
    
    std::cout << "Your points are" << std::endl;
    collection.print();
    return 0;
}
