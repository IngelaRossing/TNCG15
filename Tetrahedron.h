#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Ray.h"
#include "definitions.h"
#include "Triangle.h"
#include "vector"
#include "Surface.h"



class Tetrahedron
{
    public:
        Tetrahedron(Vertex top, Vertex bot1, Vertex bot2, Vertex bot3, Surface s);
        bool rayIntersection(Ray& r);
        Vertex v0,v1,v2,v3;


    private:
        Surface tSurface;






};

#endif // TETRAHEDRON_H
