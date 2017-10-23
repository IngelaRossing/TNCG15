#include "Surface.h"

Surface::Surface(const ColorDbl &color)
{
    //ctor
}

ColorDbl Surface::diffuseReflection()
{
    return color*reflectionCoefficient/PI;
}
