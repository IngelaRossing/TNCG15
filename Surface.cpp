#include "Surface.h"

Surface::Surface(const ColorDbl &color, const sSurfaceType type)
:color(color), surfaceType(type)
{
    //ctor
}

ColorDbl Surface::detSurface()
{
    if(surfaceType==diffuse)
    {
       std::cout<<"Diffuse"<<std::endl;
       return diffuseReflection();
    }
    else if(surfaceType==specular)
        return specularReflection();

    std::cout<<"Error no valid surface"<<std::endl;
    return color;
}

ColorDbl Surface::diffuseReflection()
{
    return color*reflectionCoefficient/PI;
}

ColorDbl Surface::specularReflection()
{
    return color;
}
