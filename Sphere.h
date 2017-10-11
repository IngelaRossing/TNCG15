#ifndef SPHERE_H
#define SPHERE_H

#include "Ray.h"
#include "definitions.h"


class Sphere
{
public:
    Sphere(float radius,Vertex center);
    bool rayIntersection(Ray& r);
    float getRadius(){return sRadius;}
    Vertex getCenter(){return sCenter;} //Don't know if we need but was bored and wanted to code

private:
    float sRadius;
    Vertex sCenter;
};
#endif
