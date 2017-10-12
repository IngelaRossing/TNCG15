#include "Scene.h"

//Find intersected triangle, passes references to the triangle and the intersections point to Ray ray
void Scene::getIntersection(Ray& ray)
{
    //successively call rayIntersection
    for (int i = 0; i< T_SIZE; i++)  //for all triangles
    {
        if( triangles[i].rayIntersection(ray))
        {
            //std::cout << "found intersection with triangle " << i << std::endl;
            std::cout << "*";
            return; //find only first

        }

    }
    std::cout << " "; //no intersection found
    ray.setColor(ColorDbl(0,0,0));
}
