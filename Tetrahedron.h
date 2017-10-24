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



    private:
        Surface tSurface;
        Vertex v0,v1,v2,v3;
        Triangle triangles[3];

};

//           top
//           / \
            / . \
           /  .  \
          /   .   \
         /    .    \
   bot1 /_ _ _. _ _ \bot2
//           bot3



#endif // TETRAHEDRON_H
