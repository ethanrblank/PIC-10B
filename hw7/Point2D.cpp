#include "Point2D.h"

std::ostream& operator<<(std::ostream& out, const Point2D& point) {
    out << "(" << point.get_x() << ", " << point.get_y() << ")";
    return out;
}

Point2D::Point2D() {
    x = NULL;
    y = NULL;
}

Point2D::Point2D(double init_x, double init_y):x(init_x), y(init_y) {}

/*
 @param x_shift
 @param y_shift
 shift_by() takes in an x value and a y value and shifts a 2D point updates the x and y private variables by the amount */

void Point2D::shift_by(double x_shift, double y_shift) {
    x += x_shift;
    y += y_shift;
}

/* quadrant() gives returns an int value that corresponds with the quadrant that a certain point is located in */

int Point2D::quadrant() const {
    int quadrant;
    
    if (x>0 && y>0)
        quadrant = 1;
    else if (x<0 && y>0)
        quadrant = 2;
    else if (x<0 && y<0)
        quadrant = 3;
    else if (x>0 && y<0)
        quadrant = 4;
    
    return quadrant;
}

/*
 @print (x,y)
 print function prints the x and y values for a Point2D object to the console
 */

void Point2D::print() const {
    std::cout << "(" << x << "," << y << ")";
}

