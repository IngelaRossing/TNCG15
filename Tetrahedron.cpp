#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(Vertex top, Vertex bot1, Vertex bot2, Vertex bot3, Surface s)
                        :v0(top), v1(bot1), v2(bot2), v3(bot3), tSurface(s)
{
    ColorDbl c{1,1,1};

    Triangle t0(v0, v1, v2,c);
    Triangle t1(v0, v3, v1, c);
    Triangle t2(v0, v2, v3, c);
    Triangle t3(v3, v2, v1, c);


}

bool Tetrahedron::rayIntersection(Ray& r)
{


}

