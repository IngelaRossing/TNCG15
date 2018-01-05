#include "Lightsource.h"

Lightsource::Lightsource(Vertex p0, Vertex p1, Vertex p2, Vertex p3, Surface s)
                        :v0(p0), v1(p1), v2(p2), v3(p3), lSurface(s)
{
    ColorDbl c{1,1,1};
    triangles[0]=Triangle(v0, v2, v1, c);
    triangles[1]=Triangle(v1, v2, v3, c);
}

bool Lightsource::rayIntersection(Ray& r)
{
    if(triangles[0].rayIntersection(r)||triangles[1].rayIntersection(r))
        return true;
    return false;
}
