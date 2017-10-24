#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(Vertex top, Vertex bot1, Vertex bot2, Vertex bot3, Surface s)
                        :v0(top), v1(bot1), v2(bot2), v3(bot3), tSurface(s)
{
    ColorDbl c{1,1,1};

    triangles[0]=Triangle(v0, v1, v2,c);
    triangles[1]=Triangle(v0, v3, v1, c);
    triangles[2]=Triangle(v0, v2, v3, c);
    triangles[3]=Triangle(v3, v2, v1, c);


}

bool Tetrahedron::rayIntersection(Ray& r)
{
    if(triangles[0].rayIntersection(r)||triangles[1].rayIntersection(r)||triangles[2].rayIntersection(r)||triangles[3].rayIntersection(r))
        return true;
    return false;

}

