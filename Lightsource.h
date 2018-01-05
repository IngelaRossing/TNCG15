#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Ray.h"
#include "definitions.h"
#include "Triangle.h"
#include "vector"
#include "Surface.h"

class Lightsource
{
    public:
        Lightsource(Vertex p0, Vertex p1, Vertex p2, Vertex p3, Surface s);
        bool rayIntersection(Ray& r);



    private:
        Surface lSurface;
        Vertex v0,v1,v2,v3;
        Triangle triangles[2];
};


// v0-----v1
// |    /  |
// |   /   |
// |  /    |
// v2-----v3
#endif // LIGHTSOURCE_H
