#include "Scene.h"

//Find intersected triangle, passes references to the triangle and the intersections point to Ray ray
void Scene::getIntersection(Ray& ray)
{
    bool found = false;
    //Find first intersection

    //successively call rayIntersection
    for (int i = 0; i< T_SIZE; i++)  //for all triangles
    {
        //returns a bool so we can quit when we find first in scene, since we always intersect only one of the scene triangles
        if (triangles[i].rayIntersection(ray))
            //already TRIANGLE if true
            break; //since the scene is only walls that never overlap no more intersection is found
            //HOW DOES TETRAHEDRON WORK?
    }
    //if sphere is closer it will change r and hitTriangle will be set to nullptr
}
