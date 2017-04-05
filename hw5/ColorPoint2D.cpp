#include "ColorPoint2D.h"

/* @constr constructor for a ColorPointer2D object by utilizing a Point2D object and a string the determines color */

ColorPoint2D::ColorPoint2D(double init_x, double init_y, std::string init_color):Point2D(init_x, init_y), color(init_color) {}

/* overloaded .print() operator from Point2D class for a ColorPoint2D that prints the Point2D variables as well as the name of the color */

void ColorPoint2D::print() const {
    std::cout << color;
    Point2D::print();
}
