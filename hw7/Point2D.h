#ifndef Point2D_h
#define Point2D_h

#include <iostream>
#include <cmath>

/** @class Point2D
 @brief class stores x and y coordinates
 
 This class is designed to take a x and y coordinates in order to form points. The class includes shift functions, a quadrant function that returns the quadrant that the point is in, and a print function to print the point to the console.
 **/

class ColorPoint2D;
class WeightedPoint2D;

class Point2D {
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
public:
    Point2D();
    Point2D(double init_x, double init_y);
    void shift_by(double x_shift, double y_shift);
    int quadrant() const;
    virtual void print() const;
    inline double dist() const {return (sqrt(pow(this->x,2.0) + pow(this->y,2.0)));}
    inline double get_x() const {return x;}
    inline double get_y() const {return y;}
    inline virtual int type() const { return 0;}
    inline virtual double get_weight() const { return 0;}
    inline virtual std::string get_color() const { return "";}

private:
    double x;
    double y;
};

#endif /* Point2D_h */
