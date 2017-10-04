#include "Triangle.h"


Triangle::Triangle(Vertex &vi0, Vertex &vi1, Vertex &vi2, ColorDbl& cl)
    : v0(vi0), v1(vi1), v2(vi2), triangle_color(cl)
{

    //calculate normal
    Direction side1 = Direction(v1.x-v0.x, v1.y-v0.y, v1.z-v0.z);
    Direction side2 = Direction(v2.x-v0.x, v2.y-v0.y, v2.z-v0.z);
    normal = glm::normalize(glm::cross(side1, side2));

    std::cout << "Created triangle with normal (" << normal.x << "," << normal.y << "," << normal.z << ")\n";
}

Vertex Triangle::rayIntersection(Ray& r)
{
    Vertex pe=r.getStart();
    Vertex ps=r.getEnd();
    glm::vec3 T=ps-v0;
    glm::vec3 E1=v1-v0;
    glm::vec3 E2=v2-v0;
    glm::vec3 D=pe-ps;

    glm::vec3 P=glm::cross(D,E2);
    glm::vec3 Q=glm::cross(T,E1);

    float det = glm::dot(E1,P);

    // if the determinant is negative the triangle is backfacing
    // if the determinant is close to 0, the ray misses the triangle
    if (det < 0.00001) return Vertex(); //If culling

    // ray and triangle are parallel if det is close to 0
    //Ray is parallell to triangle and misses
    if (fabs(det) < 0.00001) return Vertex();
    //std::cout << "ray is incoming from a good direction\n";

    float invDet=1/det;

    float u=glm::dot(P,T)*invDet;
    float v=glm::dot(Q,E2)*invDet;


    //Now we test if it hits the triangle
    if (u < 0 || u > 1) return Vertex();

    if (v < 0 || u + v > 1) return Vertex();

    float t=glm::dot(Q,E2)*invDet;

    return Vertex(ps.x+t*D.x, ps.y+t*D.y, ps.z+t*D.z, 1);

    //return Vertex(u*E1.x+v*E2.x-t*D.x+v0.x, u*E1.y+v*E2.y-t*D.y+v0.y, u*E1.z+v*E2.z-t*D.z+v0.z, 1);
}
