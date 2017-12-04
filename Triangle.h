#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "glm/glm.hpp"
#include "Ray.h"
#include "definitions.h"
#include <iostream>
#include "Surface.h"


class Triangle{
private:
Vertex v0,v1,v2;
ColorDbl triangle_color;
Direction normal;
Surface surface;

public:
    Triangle(Vertex& vi0, Vertex& vi1, Vertex& vi2, ColorDbl& cl);
    Triangle();
    Direction getNormal(){return normal;}
    Surface getSurface(){return surface;}

    // Computes the intersection between a ray and the Triangle with the Möller-Trumbore algorithm.
    bool rayIntersection(Ray& r);
};
#endif
