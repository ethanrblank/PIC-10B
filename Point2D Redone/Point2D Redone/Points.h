/** @file Points.h
    @author [Ethan Blank]
    @date [12/20/16]
 
    @class Points
    @brief [A class that stores Point2D pointers in a vector.]
 */

#ifndef Points_h
#define Points_h

#include "Point2D.h"
#include <vector>


class Points {
public:
    
    Points();
    ~Points();
    void push_back(Point2D*);
    void print() const;

private:
    std::vector<Point2D*> points;
    
};

#endif /* Points_h */
