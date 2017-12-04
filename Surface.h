#ifndef SURFACE_H
#define SURFACE_H

#include "definitions.h"
#include "Ray.h"


class Surface
{
    public:
        /*enum sSurfaceType
        {
            diffuse,
            specular
        };*/
        Surface(const ColorDbl &color = ColorDbl(0,0,0), const surfaceType type = diffuse);
        ColorDbl detSurface(); //Used to determine the surface of the object
        ColorDbl diffuseReflection();
        ColorDbl specularReflection();

        //Direction reflectedRay(Ray& in, Direction normal); //returns a ray reflected from intersectionpoint

        surfaceType type;

    private:
        ColorDbl color;
        double reflectionCoefficient=3; //Probably wanna change this later
        double PI=3.14159265359;
};

#endif // SURFACE_H
