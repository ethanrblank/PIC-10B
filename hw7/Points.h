#ifndef Points_h
#define Points_h

/** @class Points
 @brief a class the stores the points that are on the heap in a vector
 
 This class creates a vector of stored Point2D&family objects on the heap. It has a print function to print the points to the console. After the Points objects moves out of scope, the memory on the heap is deleted.
 **/

#include <iostream>
#include <vector>
#include "Point2D.h"
#include "ColorPoint2D.h"
#include "WeightedPoint2d.h"

class Points {
public:
    Points() {}
    void push_back(Point2D* pt);
    void print() const;
    ~Points() {
        for(auto& x : points)
            delete x;
    }
    
    void sort();
    
private:
    std::vector<Point2D*> points;
};

#endif /* Points_hpp */
