#include "Camera.h"

void Camera::render(){

    for (int r = 0; r < WINDOW_SIZE; r++)
    {
        for (int c = 0; c < WINDOW_SIZE; c++)

        {
            std::cout << r << "," << c << "  ";
            //send out one ray for each pixel into the scene
            float delta = 2/float(WINDOW_SIZE);

            //camera plane goes between (0,-1, -1) and (0,1,1)
            // point of intersection through the center of pixels[r][c]
            Vertex px = Vertex(0, -1 + ( 0.5+r )*delta, -1 + (0.5+c)*delta,0);
            //std::cout << px.y <<"," <<px.z << " ";

            Vertex pe = eyes[eye];
            Direction D = glm::normalize(px - pe);
           // std::cout << "D: " << D.x << D.y << D.z << " ";

            Vertex ps = Vertex(pe.x+30*D.x, pe.y+30*D.y, pe.z+30*D.z,0);
            //std::cout << "ps: " << ps.x << "," << ps.y << ","<< ps.z << " \n";
            //We create a white ray with end point somewhere far in the direction D from eye point
            Ray * ray = new Ray( ps, eyes[eye], ColorDbl(1,1,1) );

            //find first intersection by checking intersection with all triangles in the scene and save triangle and point in ray
            scene.getIntersection(*ray);

            //get color from BRDF which only depends on surface color and inclination angle and save in the ray


            pixels[r][c].intersecting_rays.push_back(ray); //Store ray in pixel

        }
    }
}
