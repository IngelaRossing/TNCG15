#include <iostream>
#include "glm/glm.hpp"

//TODO: fix this! It does not work
using Vertex = glm::vec4; //three spatial coordinates x,y,z and w for homogeneous coordinates
using Direction =glm::vec3; //direction vector (x,y,z)
using ColorDbl = double[3]; //three double prec. variables for RGB intensities


//TODO: Constructors
struct Ray{
    //It could also be references if we want to point to the vertex list
    Vertex start_point;
    Vertex end_point;

    ColorDbl ray_color;

    //Ray contains a reference to the triangle on which the end point is located.
    Triangle& hit_triangle;

};


class Triangle{
private:
Vertex v0,v1,v2;
ColorDbl triangle_color;
Direction normal;

public:
    Triangle(Vertex& vi0, Vertex& vi1, Vertex& vi2, ColorDbl cl);
    //Triangle(); //FIX
    // Computes the intersection between a ray and the Triangle with the Möller-Trumbore algorithm.
    //Vertex rayIntersection(Ray r); //Not sure if it should return a Vertex..

};

Triangle::Triangle(Vertex &vi0, Vertex &vi1, Vertex &vi2, double *cl)
    : v0(vi0), v1(vi1), v2(vi2)
{
    //copy values from cl or fix class
    //calculate normal
}

// The scene is always a hexagon room
class Scene{

    //different colors for the walls, white floor and ceiling
    ColorDbl white{1,1,1};
    ColorDbl w1{1,0,0}; //red
    ColorDbl w2{1,1,0}; //yellow
    ColorDbl w3{0,1,1}; //cyan
    ColorDbl w4{0,0,1}; //blue
    ColorDbl w5{1,0,1}; //magenta
    ColorDbl w6{0,1,0}; //green

    //list of all vertices
    Vertex v[12]{
            Vertex(-3,0,5,0), //top 0-5
            Vertex(0,6,5,0),
            Vertex(10,6,5,0),
            Vertex(13,0,5,0),
            Vertex(10,-6,5,0),
            Vertex(0,-6,5,0),

            Vertex(-3,0,-5,0), //bottom 6-11
            Vertex(0,6,-5,0),
            Vertex(10,6,-5,0),
            Vertex(13,0,-5,0),
            Vertex(10,-6,-5,0),
            Vertex(0,-6,-5,0)
    };

    Triangle triangle_table[20]{ //Fuck. Normalerna borde ju vara inåt

            Triangle(v[2], v[0],  v[1],white),   //top 0-3
            Triangle(v[4], v[2], v[3],white),
            Triangle(v[5], v[0], v[4],white),
            Triangle(v[4], v[0], v[2],white),

            Triangle(v[11], v[10], v[6],white), //bottom 4-7
            Triangle(v[9], v[8], v[10],white),
            Triangle(v[7], v[6], v[8],white),
            Triangle(v[8], v[6], v[10],white),

            Triangle(v[1], v[0], v[7], w1),      //red wall
            Triangle(v[7], v[0], v[6], w1),
            Triangle(v[2], v[1], v[8], w2),      //yellow wall
            Triangle(v[8], v[1], v[7], w2),
            Triangle(v[3], v[2], v[9], w3),      //cyan wall
            Triangle(v[9], v[2], v[8], w3),
            Triangle(v[4], v[3], v[10], w4),     //blue wall
            Triangle(v[10], v[3], v[9], w4),
            Triangle(v[5], v[4], v[11], w5),     //magenta wall
            Triangle(v[11], v[4], v[10], w5),
            Triangle(v[0], v[5], v[6], w6),      //green wall
            Triangle(v[6], v[5], v[11], w6)

    };
};


class Pixel{
    ColorDbl color; //Holds color and intensity for this pixel with a HDR
//    Ray& intersecting_rays[]{};
};

class Camera{
    Vertex eye1, exe2;
    Pixel window[1000][1000]{};

public:
    void render(); //launches a ray through each pixel one at a time and changes pixel color
};

int main() {


    Scene scene{};
    Vertex v{1,2,3,4};

    std::cout << "Vertex v:"  << v.x << std::endl;
    return 0;
}

