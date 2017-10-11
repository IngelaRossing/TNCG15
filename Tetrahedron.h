#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Ray.h"
#include "definitions.h"
#include "Triangle.h"



class Tetrahedron
{
    public:
        Tetrahedron(Vertex top, Vertex bot1, Vertex bot2, Vertex bot3);
        bool rayIntersection(Ray& r);

    private:


};

#endif // TETRAHEDRON_H
