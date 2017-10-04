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
    for (auto& arrayOuter : intArr)
    {
        for (auto& pixel : arrayOuter)

        {
            //send out one ray for each pixel into the scene
            //find first intersection by checking intersection with all triangles in the scene
            //get color from BRDF which only depends on surface color and inclination angle and save in the pixel

            std::cout << pixel;
        }
        std::cout << std::endl;
    }
}
