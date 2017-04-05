/** @file Point2D.h
    @author [Ethan Blank]
    @date [12/20/16]
 
    @brief [A set of three classes (Point2D, ColorPoint2D, WeightedPoint2D). The Color and Weighted classes are inherited from the Point2D class.]
 */

#ifndef Point2D_h
#define Point2D_h

#include <iostream>

class Point2D {
public:
    Point2D();
    Point2D(double, double);
    virtual ~Point2D() {}
    virtual void print() const;
private:
    double x;
    double y;
};

class ColorPoint2D : public Point2D {
public:
    ColorPoint2D();
    ColorPoint2D(double, double, std::string);
    ~ColorPoint2D() {}
    void print() const;
private:
    std::string color;
};

class WeightedPoint2D : public Point2D {
public:
    WeightedPoint2D();
    WeightedPoint2D(double, double, double);
    ~WeightedPoint2D() {}
    void print() const;
private:
    double weight;
};
#endif /* Point2D_h */
