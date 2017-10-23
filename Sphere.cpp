#include "Sphere.h"
#include <cmath>

Sphere::Sphere(float radius, Vertex center, Surface s)
    :sRadius(radius), sCenter(center), sSurface(s)
{

}
bool Sphere::rayIntersection(Ray& r)
{
    //This is pretty straight forward. We just implement the equation given in the CodeOutline

    float rad=sRadius;

    Vertex o=r.getStart();
    Vertex e=r.getEnd();
    glm::vec3 l=o-e; //direction

    l=glm::normalize(l);

    Vertex cen=sCenter; //center

    //We calculate the vector from the ray origin to the center of the sphere
    glm::vec3 oc=o-cen;

    float b=glm::dot(l*2.0f,oc);

    if(b<0.000001) return false; //We do not intersect the sphere

    float d1=-(b/2.0f);

    float c=glm::dot(oc,oc)-rad*rad;

    float secondPart=d1*d1-c;


    if(secondPart<-0.000001) return false; //complex

    float d2=d1;

    float sd=std::sqrt(secondPart);



    d1+=sd; //If the ray is on the positive side of the center I think??
    d2-=sd; //If the ray is on the negative side of the center I think??

    if(d1>0.000001) return true; //We intersect with the sphere
    else if(d2>0.000001) return true; //We intersect with the sphere

    return false; //We do not
}

