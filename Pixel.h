#ifndef PIXEL_H
#define PIXEL_H

#include "definitions.h"
#include "Ray.h"

#include <vector>

class Pixel{
    ColorDbl color; //Holds color and intensity for this pixel with a HDR
    std::vector<Ray*> intersecting_rays;
};
#endif // PIXEL_H
