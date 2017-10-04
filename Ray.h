#ifndef RAY_H
#define RAY_H

#include "definitions.h"

class Ray{
private:
    Vertex start_point;
    Vertex end_point;

    ColorDbl ray_color ;

    //Ray contains a reference to the triangle on which the end point is located.
    //Triangle& hit_triangle;

public:
     Ray(Vertex& startP, Vertex& endP, ColorDbl c);
     Vertex getStart() {return start_point;}
     Vertex getEnd() {return end_point;}

};
#endif
