#ifndef SURFACE_H
#define SURFACE_H

#include "definitions.h"
#include "Ray.h"


class Surface
{
    public:
        Surface() : color (ColorDbl(0,0,0)), surfaceType(diffuse){}
        Surface(const ColorDbl &color, const sSurfaceType type);
        ColorDbl detSurface(); //Used to determine the surface of the object
        ColorDbl diffuseReflection();
        ColorDbl specularReflection();
        ColorDbl getColor(){return color;}

        //Direction reflectedRay(Ray& in, Direction normal); //returns a ray reflected from intersectionpoint

        sSurfaceType surfaceType;

    private:
        ColorDbl color;
        double reflectionCoefficient=3; //Probably wanna change this later
        double PI=3.14159265359;
};

#endif // SURFACE_H
