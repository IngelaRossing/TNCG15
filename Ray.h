#ifndef RAY_H
#define RAY_H

#include "definitions.h"

class Triangle;
class Sphere;

class Ray{
private:
    Vertex start_point;
    Vertex end_point;

    ColorDbl ray_color ;

    //Ray contains a reference to the triangle on which the end point is located.
    Triangle* hit_triangle = nullptr;
    Sphere* hit_sphere = nullptr;

public:
     Ray(Vertex& startP, Vertex& endP, ColorDbl c);
     Vertex getStart() {return start_point;}
     Vertex getEnd() {return end_point;}
     void setEnd(Triangle* ht, Vertex& ps); //Update closest intersection
     void setEnd(Sphere* hs, Vertex& ps); //same for spheres

     Triangle* getHitTriangle(){return hit_triangle;}
     Sphere* getHitSphere(){return hit_sphere;}
     Direction getDirection(){return Direction(end_point.x-start_point.x, end_point.y-start_point.y, end_point.z-start_point.z);}

     ColorDbl getColor() {return ray_color;}
     ColorDbl setColor(ColorDbl c) {ray_color = c;}


};
#endif
