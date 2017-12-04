#include "Triangle.h"

//This is a sad sad fix of the problem
Triangle::Triangle()
{
    std::cout << "Created fake triangle\n";
}

Triangle::Triangle(Vertex &vi0, Vertex &vi1, Vertex &vi2, ColorDbl& cl) //add surface type
    : v0(vi0), v1(vi1), v2(vi2), triangle_color(cl)
{

    //calculate normal
    Direction side1 = Direction(v1.x-v0.x, v1.y-v0.y, v1.z-v0.z);
    Direction side2 = Direction(v2.x-v0.x, v2.y-v0.y, v2.z-v0.z);
    normal = glm::normalize(glm::cross( side1, side2 ));

    surface = Surface(cl, diffuse);

    std::cout << "Created triangle with normal (" << normal.x << "," << normal.y << "," << normal.z << ")\n";
}

bool Triangle::rayIntersection(Ray& r)
{
    Vertex ps = r.getStart();
    Vertex pe = r.getEnd(); //Used for finding D, old first found triangle intersection with r
    glm::vec3 E1 = v1-v0;
    glm::vec3 E2 = v2-v0;
    glm::vec3 T = ps-v0;
    glm::vec3 D = pe-ps;

   /* std::cout<<"V0: "<<v0.x<<","<<v0.y<<","<<v0.z<<std::endl;
    std::cout<<"V1: "<<v1.x<<","<<v1.y<<","<<v1.z<<std::endl;
    std::cout<<"V2: "<<v2.x<<","<<v2.y<<","<<v2.z<<std::endl;
    */
    glm::normalize(D);
    glm::vec3 P=glm::cross(D,E2);

    float det = glm::dot(E1,P);

    // if the determinant is negative the triangle is backfacing
    // if the determinant is close to 0, the ray misses the triangle
    if (det < 0.000000001f) return false; //If culling

    // ray and triangle are parallel if det is close to 0
    //Ray is parallell to triangle and misses
    if (fabs(det) < 0.00000001f) return false;
    //std::cout << "ray is incoming from a good direction\n";

    //A point on the triangle can be found as T(u,v)
    //We calculate v after testing u for efficiency
    float invDet = 1.0f/det;
    float u=glm::dot(P,T)*invDet; //T is not yet correct! D: TRYING WITH TRIANGLE NORMAL

    //first test if it hits the triangle
    if (u < 0.0f || u > 1.0f) return false;

    glm::vec3 Q=glm::cross(T,E1);
    float v=glm::dot(Q,D)*invDet;

    //last test if it hits the triangle
    if (v < 0.0f || u + v > 1.0f) return false;

    //std::cout << " Found intersection! ";

    //t is the proportion of D that is needed to go from the triangle to the ray
    float t = glm::dot(E2,Q)*invDet;

    //if we are behind eye or have a previous intersection closer, we don't update ray and return false even if we have an intersection!
    if( t > 1.0f || t <= 0.0f ) //closer than prev but in fron of eye if 0 > t > 1
        return false;
    else
    {

        T = u*E1 + v*E2 - t*D; //vector from v0 to intersection point ip on triangle
        Vertex ip = Vertex(v0.x+T.x, v0.y+T.y, v0.z+T.z, 1);

        //ray gets a new intersection point endP = ip and new hit_triangle = this
        r.setEnd(this, ip);

        //Set ray color to triangle color but alsodependent on normal
        //r.setColor(triangle_color * double(glm::dot( normal, glm::normalize(-D) ))); //SHOULD BE DONE OUTSIDE THIS FUNCTION

        return true;
    }
}
