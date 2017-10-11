#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(Vertex top, Vertex bot1, Vertex bot2, Vertex bot3)
{
    ColorDbl c{1,1,1};

    Triangle t[4]={Triangle(top, bot1, bot2, c),
                   Triangle (top, bot1, bot2, c),
                   Triangle(top, bot2, bot3, c),
                   Triangle(top, bot3, bot1, c)
                   };
}
bool Tetrahedron::rayIntersection(Ray& r)
{


}

