#ifndef RAY_H
#define RAY_H

#include "definitions.h"
class Triangle;

class Ray{
private:
    Vertex start_point;
    Vertex end_point;

    ColorDbl ray_color ;

    //Ray contains a reference to the triangle on which the end point is located.
    Triangle& hit_triangle; //It has to be explicitly initialized in constructor or we get an error

public:
     Ray(Vertex& startP, Vertex& endP, ColorDbl c,Triangle& t);
     Vertex getStart() {return start_point;}
     Vertex getEnd() {return end_point;}

};

#endif
