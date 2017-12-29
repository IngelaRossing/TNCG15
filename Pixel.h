#ifndef PIXEL_H
#define PIXEL_H

#include "definitions.h"
#include "Ray.h"

#include <vector>

class Pixel{
    ColorDbl color{0,0,0}; //Holds color and intensity for this pixel with a HDR
    std::vector<Ray*> intersecting_rays;

public:
    //friend class Camera; //to give Camera access to privates
    void addRay( Ray* r);
    ColorDbl getColor() {return color;}
};
#endif // PIXEL_H
