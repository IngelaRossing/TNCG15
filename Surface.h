#ifndef SURFACE_H
#define SURFACE_H

#include "definitions.h"
#include "Ray.h"


class Surface
{
    public:
        enum sSurfaceType
        {
            diffuse,
            specular
        };
        Surface(const ColorDbl &color, const sSurfaceType type);
        ColorDbl detSurface(); //Used to determine the surface of the object
        ColorDbl diffuseReflection();
        ColorDbl specularReflection();

        sSurfaceType surfaceType;






    private:
        ColorDbl color;
        double reflectionCoefficient=3;
        double PI=3.14;



};

#endif // SURFACE_H
