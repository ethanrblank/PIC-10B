
#ifndef WeightedPoint2D_h
#define WeightedPoint2D_h

#include "Point2D.h"

/** @derived_class WeightedPoint2D
 @brief a derivation of the Point2D class that includes the weight of the point
 
 This class operates similarly to the Point 2D class in that it stores x and y coordinates, but also contains a double for a weight variable which allows the user of the class to include weights within the points. The class utilizes the print function from the Point2D class
 **/

class WeightedPoint2D: public Point2D {
public:
    virtual void print() const;
    WeightedPoint2D(double init_x, double init_y, double init_weight);
    inline int type() const { return 2;} // returns 2 for a WeightedPoint2D object
    inline double get_weight() const { return weight;} // returns the private variable weight
    ~WeightedPoint2D();
private:
    double weight;
};

#endif /* WeightedPoint2D_h */
