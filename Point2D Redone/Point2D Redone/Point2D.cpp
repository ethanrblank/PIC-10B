/** @file Point2D.cpp
    @author [Ethan Blank]
    @date [12/20/16]
 */

#include "Point2D.h"

/** Default constructor for a Point2D object. Initializes x and y to 0 */
Point2D::Point2D() {
    x = 0;
    y = 0;
}

/** @param init_x (double)
    @param init_y (double)
 
    [Regular constructor for a Point2D object. Sets x to init_x and y to init_y.]
 */
Point2D::Point2D(double init_x, double init_y) {
    x = init_x;
    y = init_y;
}

/** [Prints the point to the console.] */
void Point2D::print() const {
    std::cout << "(" << x << ", " << y << ")";
}

/** Default constructor for a ColorPoint2D object. Initializes x and y to 0 by way of the Point2D constructor. Initializes color to an empty string. */
ColorPoint2D::ColorPoint2D() : Point2D(0,0), color("") {}

/** @param init_x (double)
    @param init_y (double)
    @param init_color (string)
    
    [Regular constructor for a ColorPoint2D object. Initializes x and y by init_x and init_y by way of the Point2D constructor. Initializes color to init_color.]
 */
ColorPoint2D::ColorPoint2D(double init_x, double init_y, std::string init_color) : Point2D(init_x, init_y), color(init_color) {}

/** Prints the color to the console, then utilizes the Point2D print function to print x and y. */
void ColorPoint2D::print() const {
    std::cout << color; Point2D::print();
}

/** Default constructor for a WeightedPoint2D object. Initializes x and y to 0 by way of the Point2D constructor. Initializes weight to 0 */
WeightedPoint2D::WeightedPoint2D() : Point2D(0,0), weight(0) {}

/** @param init_x (double)
 @param init_y (double)
 @param init_weight (double)
 
 [Regular constructor for a WeightedPoint2D object. Initializes x and y by init_x and init_y by way of the Point2D constructor. Initializes weight to init_weight.]
 */
WeightedPoint2D::WeightedPoint2D(double init_x, double init_y, double init_weight) : Point2D(init_x, init_y), weight(init_weight){}

/** Prints the weight to the console, then utilizes the Point2D print function to print x and y. */
void WeightedPoint2D::print() const {
    std::cout << weight; Point2D::print();
}
