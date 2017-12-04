#include <iostream>
#include "glm/glm.hpp"

//#include "definitions.h"
#include "Camera.h"
#include "Sphere.h"
#include "Tetrahedron.h"

using namespace std;



Scene scene;
int main() {

    //Testing surface+Sphere, seems to be working

    ColorDbl cs{0.3,0.5,0.6};

    Sphere sphere(0.15, Vertex(0.3,0.3,0.5,0),Surface(cs, diffuse));
    Surface ss=sphere.getSurface();

    ColorDbl em=ss.detSurface();

    scene.addSphere(sphere);

    //Add Tetrahedron

    std::cout << "TETRA" <<std::endl;

    Tetrahedron tetra(Vertex(1,1,1,0),Vertex(0,0,0,0),Vertex(0.5,0.5,0,0),Vertex(0,1,0,0),Surface(cs,specular));
    scene.addTetrahedron(tetra);

    std::cout << "END OF TETRA" <<std::endl;


    Vertex w{1,2,3,4};
    ColorDbl c{1,1,1};

    Camera camera;

    camera.render(scene);

    std::cout << em.x<<" "<<em.y<<" "<<em.z<<std::endl;


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





    if(t.rayIntersection(r))
        std::cout << "intersection!" << std::endl;
    else
        std::cout << "missed t\n";

    if(sphere.rayIntersection(r))
        std::cout << "intersection with sphere!" << std::endl;
    else
        std::cout << "missed sphere\n";
    if(tetra.rayIntersection(r))
         std::cout << "intersection with tetra!" << std::endl;
    else
        std::cout << "missed tetra\n";



//    std::cout << "Instersection points:"  << intersectionPoint.x<<intersectionPoint.y<<intersectionPoint.z<< std::endl;

    return 0;
}
