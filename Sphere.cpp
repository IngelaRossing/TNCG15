#include "Sphere.h"
#include <cmath>
#define EPSILON 0.00000000000000001


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
    Vertex cen=sCenter; //center
    glm::vec3 l=e-o; //direction

    l=glm::normalize(l);


    //We calculate the vector from the ray origin to the center of the sphere
    glm::vec3 oc=o-cen;

    float b=glm::dot(l*2.0f,oc);

    float d1=-b/2.0f;

    float c=glm::dot(oc,oc)-rad*rad;

    float secondPart=d1*d1-c;

    if(secondPart<-EPSILON) return false; //complex

    float d2=d1;

    float sd=std::sqrt(secondPart);

    d1+=sd;
    d2-=sd;

    if(d1>EPSILON)
    {
        /*
        Vertex intPoint=Vertex(o.x+d1*l.x, o.y+d1*l.y, o.z+d1*l.z,1);
        r.setEnd(*this,intPoint); //Probably need to do this another way since this is not a triangle
        */

        return true; //We intersect with the sphere
    }

    else if(d2>EPSILON)
    {
        /*
        Vertex intPoint=Vertex(o.x+d2*l.x, o.y+d2*l.y, o.z+d2*l.z,1);
        r.setEnd(*this,intPoint); //Probably need to do this another way since this is not a triangle
        */

       return true; //We intersect with the sphere
    }


    return false; //We do not
}
glm::vec3 Sphere::getNormal(Vertex center)
{
    return glm::normalize(center-sCenter);
}


