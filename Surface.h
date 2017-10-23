#ifndef SURFACE_H
#define SURFACE_H

#include "definitions.h"


class Surface
{
    public:
        Surface(const ColorDbl &color);
        ColorDbl diffuseReflection();



    private:
        ColorDbl color;
        double reflectionCoefficient =3;
        double PI=3.14;
};

#endif // SURFACE_H
