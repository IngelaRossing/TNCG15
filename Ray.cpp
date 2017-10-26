#include "Ray.h"

Ray::Ray(Vertex& startP, Vertex& endP, ColorDbl c)
    : start_point(startP), end_point(endP), ray_color(c)
{

}

void Ray::setEnd(Triangle* ht, Vertex& ps)
{
    hit_triangle = ht;
    end_point = ps;
}
