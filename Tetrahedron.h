#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Ray.h"
#include "definitions.h"
#include "Triangle.h"
#include "vector"



class Tetrahedron
{
    public:
        //Tetrahedron();
        bool rayIntersection(Ray& r);
        void addTetrahedron(Vertex top, Vertex bot1, Vertex bot2, Vertex bot3);

    private:
        std::vector<Triangle> tetra;




};

#endif // TETRAHEDRON_H
