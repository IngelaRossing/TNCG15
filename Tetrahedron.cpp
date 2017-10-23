#include "Tetrahedron.h"

//Tetrahedron::Tetrahedron(Vertex position);
//{


//}
void Tetrahedron::addTetrahedron(Vertex top, Vertex bot1, Vertex bot2, Vertex bot3)
{
     ColorDbl c{1,1,1};

     tetra.push_back(Triangle(top, bot1, bot2,c));
     tetra.push_back(Triangle(top, bot3, bot1, c));
     tetra.push_back(Triangle(top, bot2, bot3, c));
     tetra.push_back(Triangle(bot3, bot2, bot1, c));

}

bool Tetrahedron::rayIntersection(Ray& r)
{


}

