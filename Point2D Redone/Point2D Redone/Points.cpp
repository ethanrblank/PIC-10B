/** @file Points.cpp
    @author [Ethan Blank]
    @date [12/20/16]
 */

#include "Points.h"

/** Sets the points vector to an empty vector */
Points::Points() {
    std::vector<Point2D*> new_points(0);
    points = new_points;
}

/** Destructor cycles through the points vector and calls the neccessary destructor on its contents. */
Points::~Points() {
    for (auto& x : points) {
        delete x;
    }
}

/** @param pt (Point2D*)
    
    [Adds a Point2D* object to the back of the points vector.]
 */
void Points::push_back(Point2D* pt) {
    points.push_back(pt);
}

/** Prints the Point2D* object by calling on its print function. Prints i+1 to signify order. */
void Points::print() const {
    for (size_t i = 0, p = points.size(); i < p; ++i) {
        std::cout << i + 1 << ": "; (points[i])->print(); std::cout << std::endl;
    }
}
