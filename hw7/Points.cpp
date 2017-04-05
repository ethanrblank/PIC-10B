#include "Points.h"

/**
 Cylces through the points vector to print the dereferenced, Point2D pointer objects to the console
 **/
void Points::print() const {
int i = 1;
for(auto& x : points) {
    std::cout << i << ": ";
    x->print();
    std::cout << std::endl;
    ++i;
    }
}

/** @param pt
 Fills the points vector with Point2D pointers
 **/
void Points::push_back(Point2D* pt) {
    points.push_back(pt);
}

/** @param a
 @param b
 
 @return a < b
 
 Because the vector is filled with pointers, I had to define the value rules of different Point2D objects. First, it checks the type of the object. The value form least to greatest goes Point2D, ColorPoint2D, WeightedPoint2D. If two points were of the same type, it would then compare the distances from the origin. If two pointers are equidistant from the origin, then the function used the atan2 to determine which point had a smaller angle if the points were both Point2D objects. If the points were ColorPoint2D, the algorithm would sort alphabetically by color. If the points were WeighedPoint2D objects, it would sort be smallest to greatest weight.
 **/
bool pointerSort (Point2D* a, Point2D* b) {
    if (a->type() < b->type())
        return true;
    else if (a->type() == 1)
        if (a->dist() < b->dist())
            return a->dist() < b->dist();
    else
        return a->get_color() < b->get_color();
    else if (a->type() == 2)
        if (a->dist() < b->dist())
            return a->dist() < b->dist();
        else
            return a->get_weight() < b->get_weight();
    else if (a->dist() < b->dist())
        return true;
    else if (a->dist() == b->dist()) {
        const double pi = 3.1415926535897;
        double angle_a = atan2(a->get_y(), a->get_x());
        double angle_b = atan2(b->get_y(), b->get_x());
        if (angle_a < 0) {
            angle_a += 2*pi;
        }
        if (angle_b < 0) {
            angle_b += 2*pi;
        }
        return angle_a < angle_b;
    }

    return false;
}
/**
 Utilizes the standard std::sort algorithm, along with the rules defined in the pointerSort function, to sort the Point2D pointers in increasing value.
 **/
void Points::sort() {
    std::sort(points.begin(), points.end(), pointerSort);
}
