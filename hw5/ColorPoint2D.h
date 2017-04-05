#ifndef ColorPoint2D_h
#define ColorPoint2D_h
#include "Point2D.h"

/** @derived_class ColorPoint2D
 @brief a derivation of the Point2D class that includes the name of the color
 
 This class operates similarly to the Point 2D class in that it stores x and y coordinates, but also contains a string for a color variable which allows the user of the class to include colors within the points. The class utilizes the print function from the Point2D class
 **/

class ColorPoint2D: public Point2D {
public:
    virtual void print() const;
    ColorPoint2D(double init_x, double init_y, std::string init_color);
    inline int type() const { return 1;} // Returns 1 for a ColorPoint2D object
    inline std::string get_color() const {return color;} // returns the private variable color
    ~ColorPoint2D();
private:
    std::string color;
};

#endif /* ColorPoint2D_hpp */
