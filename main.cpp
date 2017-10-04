#include <iostream>
#include "glm/glm.hpp"

//#include "definitions.h"
#include "Camera.h"

using namespace std;

Scene scene;
int main() {

    Vertex w{1,2,3,4};
    ColorDbl c{1,1,1};

    Camera camera;
    std::cout<<"Hej";
    camera.render();

    std::cout << "Vertex v:"  << w.x << std::endl;

     Vertex v[5]{
        Vertex(0,0,0,0), //Triangle
        Vertex(1,0,0,0),
        Vertex(0,1,0,0),

        Vertex(0.3,0.3,-1,0),//Start and end point for ray
        Vertex(0.3,0.3,1,0)
     };
     Triangle t{v[0], v[1], v[2], c};
     Ray r = Ray(v[3], v[4], c);

    Vertex intersectionPoint = t.rayIntersection(r);

    std::cout << "Instersection points:"  << intersectionPoint.x<<intersectionPoint.y<<intersectionPoint.z<< std::endl;

    return 0;
}
