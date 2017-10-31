#include "Surface.h"

Surface::Surface(const ColorDbl &color, const sSurfaceType type)
:color(color), surfaceType(type)
{
    //ctor
}
/*
//returns a ray reflected from intersectionpointint
Direction Surface::reflectedRay(Ray& in, Direction normal){
    //ray2 direction, reflection R dependent on surface normal and Monte-Carlo integration
    //PDF: p(theta,phi) = cos(theta)/pi and CDF: F = (1/pi)integral(cos(theta) domega)

    return Direction(glm::normalize(glm::reflect(in.getDirection(), normal))*100.0f); //perfect specular, not using MC
 //   Vertex endP = in.getEnd() + Vertex(D.x,D.y,D.z,0.0f);

//    return Ray(in.getEnd(), endP, ColorDbl(0,0,0) ); //I think reference for points is messing up ray constructor
}*/

//Returns the ColorDbl depending on which surface we have chosen for our object
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
    return ColorDbl(0,0,0);
}

ColorDbl Surface::diffuseReflection() //Diffuse surface
{
    return color*reflectionCoefficient/PI;
}

ColorDbl Surface::specularReflection() //Specular surface
{
    return color;
}
