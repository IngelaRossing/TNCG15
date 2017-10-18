#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "glm/glm.hpp"
#include "Ray.h"
#include "definitions.h"
#include <iostream>


class Triangle{
private:
Vertex v0,v1,v2;
ColorDbl triangle_color;
Direction normal;

public:
    Triangle(Vertex& vi0, Vertex& vi1, Vertex& vi2, ColorDbl& cl);
    Triangle();

    // Computes the intersection between a ray and the Triangle with the Möller-Trumbore algorithm.
    bool rayIntersection(Ray& r); //Not sure if it should return a Vertex..
};
#endif
