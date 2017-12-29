#include "Pixel.h"

void Pixel::addRay( Ray* r)
{
    intersecting_rays.push_back(r);
    color+= r->getColor(); //Holds color and intensity for this pixel with a HDR
}
