#include "Ray.h"

Ray::Ray(Vertex& startP, Vertex& endP, ColorDbl c)
    : start_point(startP), end_point(endP), ray_color(c)
{

}

void Ray::setEnd(Triangle* ht, Vertex& ps)
{
    hit_triangle = ht;
    hit_sphere = nullptr;
    end_point = ps;
}

void Ray::setEnd(Sphere* hs, Vertex& ps)
{
    hit_triangle = nullptr;
    hit_sphere = hs;
    end_point = ps;
}

