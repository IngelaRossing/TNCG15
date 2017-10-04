#include "Ray.h"

Ray::Ray(Vertex& startP, Vertex& endP, ColorDbl c, Triangle& t)
    : start_point(startP), end_point(endP), ray_color(c), hit_triangle(t)
{

}
