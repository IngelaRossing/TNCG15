#include "Camera.h"
/*
Camera::Camera(int e)
{
    if(e == 2)
        eye = 2;
    else
        eye =1;

     eye1 = Vertex(-2,0,0,0);
     eye2 = Vertex(-1,0,0,0);
}
*/
void Camera::render(){

//through all pixels


    //TEST CASE LOOP
    int intArr[3][3] {{1,2,3}, {4,5,6}, {7,8,9}};


    //To loop through all pixels, change from intArray to window
    for (int r = 0; r < WINDOW_SIZE; r++)
    {
        for (int c = 0; c < WINDOW_SIZE; c++)

        {
            //send out one ray for each pixel into the scene

            float delta = 2/float(WINDOW_SIZE);

            //camera plane goes between (0,-1, -1) and (0,1,1)
            // point of intersection through the center of pixels[r][c]
            Vertex px = Vertex(0, -1 + ( 0.5+r )*delta, -1 + (0.5+c)*delta,0);
            //std::cout << px.y <<"," <<px.z << " ";

            Direction D = px - eyes[eye];
            Vertex ps = Vertex(px.x+100*D.x, px.y+100*D.y, px.z+100*D.z,0);

            //We create a white ray with end point somewhere far in the direction D from eye point
            Ray r = Ray(eyes[eye], ps, ColorDbl(1,1,1));
           // .intersecting_rays.pushback(*r );

            //find first intersection by checking intersection with all triangles in the scene
            //scene.triangles[1]
            //get color from BRDF which only depends on surface color and inclination angle and save in the pixel
        }
        std::cout << std::endl;
    }
}
