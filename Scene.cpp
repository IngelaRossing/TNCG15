#include "Scene.h"

//Find intersected triangle, passes references to the triangle and the intersections point to Ray ray
void Scene::getIntersection(Ray& ray)
{

    //Find first intersection
    //call rayIntersection for all objects in scene
    //if sphere is closer it will change r and hitTriangle will be set to nullptr

    for(int i = 0; i < spheres.size(); i++)
        spheres[i].rayIntersection(ray);

    for(int i = 0; i < tetrahedrons.size(); i++)
        tetrahedrons[i].rayIntersection(ray);

    for (int i = 0; i< T_SIZE; i++)  //for the walls
    {
        //returns a bool so we can quit when we find first in scene, since we always intersect only one of the scene triangles
        if (triangles[i].rayIntersection(ray))
            //already TRIANGLE if true
            break; //since the scene is only walls that never overlap no more intersection can be found
    }
}
