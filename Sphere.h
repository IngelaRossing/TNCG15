#ifndef SPHERE_H
#define SPHERE_H

#include "Ray.h"
#include "definitions.h"
#include "Surface.h"


class Sphere
{
public:
    Sphere(float radius,Vertex center, Surface s);
    bool rayIntersection(Ray& r);
    float getRadius(){return sRadius;}
    Vertex getCenter(){return sCenter;} //Don't know if we need but was bored and wanted to code
    Surface getSurface(){return sSurface;}
    glm::vec3 getNormal(Vertex center);

private:
    float sRadius;
    Vertex sCenter;
    Surface sSurface;
};
#endif
