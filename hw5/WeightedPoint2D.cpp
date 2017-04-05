#include "WeightedPoint2D.h"

/* @constr regular constructor for a WeightedPoint2D object */

WeightedPoint2D::WeightedPoint2D(double init_x, double init_y, double initWeight):Point2D(init_x, init_y), weight(initWeight) {}

/* overloaded .print() operator from Point2D class for a WeightedPoint2D that prints the Point2D variables as well as the name of the color */

void WeightedPoint2D::print () const {
    std::cout << weight;
    Point2D::print();
}
