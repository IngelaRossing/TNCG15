#include "Camera.h"

void Camera::render(){

    for (int r = 0; r < WINDOW_SIZE; r++)
    {
        for (int c = 0; c < WINDOW_SIZE; c++)

        {
            //std::cout << r << "," << c << "  ";

            //send out one ray for each pixel into the scene
            float delta = 2/float(WINDOW_SIZE);

            //camera plane goes between (0,-1, -1) and (0,1,1) which gives
            // point of intersection through the center of pixels[r][c]
            Vertex px = Vertex(0.0f, -1.0f + ( 0.5f+r )*delta, -1.0f + (0.5f+c)*delta, 0.0f);
            //std::cout << "("<< px.y <<"," <<px.z << ") in camera plane ";

            Vertex pe = eyes[eye]; //user chooses wich eye to use with variable eye

            glm::vec4 D = glm::normalize(pe - px) * 30.0f; //a vector D with length 30, intersecting pixel on its way to the eye
           // std::cout << "D: " << D.x << D.y << D.z << " ";

            Vertex ps =  pe - D; //endpoint   //Vertex(pe.x-*D.x, pe.y-*D.y, pe.z-*D.z, 0);
            //std::cout << "ps: " << ps.x << "," << ps.y << ","<< ps.z << " \n";
            //We create a white ray with end point somewhere far in the direction D from eye point
            Ray * ray = new Ray( ps,pe,  ColorDbl(1,1,1) ); //NOTE: ray could be deallocated after function render is done

            //find first intersection by checking intersection with all triangles in the scene and save triangle and point in ray
            scene.getIntersection(*ray);

            //DEBUGGING COMMENT: We should be able to see intersections mostly with triangle 12-15 with our scene

            //get color from BRDF which only depends on surface color and inclination angle and save in the ray
            //it is now done inside getIntersection, but it probably can't when we want to reflect the ray

            pixels[r][c].intersecting_rays.push_back(ray); //Store ray in pixel

        }
        //std::cout << std::endl;
    }
    std::cout << "\n\nIF RAY IN PIXEL:\n\n";
    createImage();
}

//Convert pixel data to 2D array of rgb-vectors
void Camera::createImage()
{
    std::array<std::array<ColorDbl, WINDOW_SIZE>, WINDOW_SIZE> image; //RGB vector 2D-array
    std::ofstream red, green, blue;

    //choose some nice path where you want them
    red.open ("Documents/MATLAB/globaltest/red.txt");
    green.open ("Documents/MATLAB/globaltest/green.txt");
    blue.open ("Documents/MATLAB/globaltest/blue.txt");

    //read colors into rgbchannels
    for (int r = 0; r < WINDOW_SIZE; r++)
    {
        for (int c = 0; c < WINDOW_SIZE; c++)

        {
            image[r][c] = pixels[r][c].intersecting_rays[0]->getColor();


            double color = image[r][c][0] + image[r][c][1] + image[r][c][2]; //black and white without truncating
            if(color < 1)
                std::cout << "@";
            else if(color < 2)
                std::cout << "o";
            else
                std::cout << ".";

            //a file for each channel
            red << image[r][c][0] << " ";
            green << image[r][c][1] << " ";
            blue << image[r][c][2] << " ";

        }
        red << std::endl;
        green << std::endl;
        blue << std::endl;

         std::cout << std::endl;
    }
    red.close();
    green.close();
    blue.close();

}
