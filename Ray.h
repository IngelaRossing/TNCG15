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
    Triangle* hit_triangle = nullptr;

public:
     Ray(Vertex& startP, Vertex& endP, ColorDbl c);
     Vertex getStart() {return start_point;}
     Vertex getEnd() {return end_point;}
     ColorDbl getColor() {return ray_color;}
     ColorDbl setColor(ColorDbl c) {ray_color = c;}
     void setEnd(Triangle* ht, Vertex& ps);

};
#endif
