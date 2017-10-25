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
            Ray * ray = new Ray(  ps, pe, ColorDbl(1,1,1) ); //NOTE: ray could be deallocated after function render is done

            //CAST RAY, let it get reflected into the scene

            //find first intersection by checking intersection with all triangles in the scene and save triangle and point in ray
            scene.getIntersection(*ray); //WILL BE DONE INSIDE castRay

            //DEBUGGING COMMENT: We should be looking directly at triangle 12-15 (blue and cyan wall) within our scene

            //get color from BRDF which only depends on surface color and inclination angle and save in the ray
            //it is now done inside getIntersection, but it probably can't when we want to reflect the ray

            pixels[r][c].intersecting_rays.push_back(ray); //Store ray in pixel

        }
        //std::cout << std::endl;
    }
    std::cout << "\n\nIF RAY IN PIXEL:\n\n";
    createImage();
}

//Let a ray spread from ray startingpoint into scene with ray.direction and get its color, which might be dependent on its reflections
ColorDbl Camera::castRay(Ray &ray, int depth)
{
    //Find first intersection
    //We need to check if we intersect a sphere or triangle first

    //If first intersection is with a triangle:
        //check if we should reflect a ray
        //don't reflect if surface is diffuse, depth > MAX_REFLECTIONS, contribution of next ray < THRESHOLD

        //If no reflection:
        //return BRDF;

        //If reflection:
        //calculate how much of the light gets, dependent on surfaceproperties and geometric, later with Oren-Nayar diffuse reflection
        //ColorDbl BRDF =

        //ray2 direction, reflection R dependent on triangle normal and Monte-Carlo integration
        //PDF: p(theta,phi) = cos(theta)/pi and CDF: F = (1/pi)integral(cos(theta) domega)

        //Ray ray2 = Ray(ray.getEnd(), ray.getEnd() + 30.0f* R, ColorDbl(1,1,1));

    //If first intersection is with a sphere:
        //If no reflection: return BRDF
        //Calculate BRDF and ray2 in another way

    //Lambertian BRDF = rho/ pi, where rho is a constant refl. coeff.
    //importance of ray is given by BRDF and color of radiance getting reflected into ray
    //ray->ray_color = elementwise multiplication(BRDF, castRay(ray2, depth + 1));

}

//Convert pixel data to 2D array of rgb-vectors
void Camera::createImage()
{
    std::array<std::array<ColorDbl, WINDOW_SIZE>, WINDOW_SIZE> image; //RGB vector<double> 2D-array
    std::ofstream red, green, blue;

    //Right now i write to three diggerent files, but it should be a 3d array with vec3
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


            /*double color = image[r][c][0] + image[r][c][1] + image[r][c][2]; //black and white without truncating
            if(color < 1)
                std::cout << "@";
            else if(color < 2)
                std::cout << "o";
            else
                std::cout << ".";*/

            //a file for each channel
            red << image[r][c][0] << " ";
            green << image[r][c][1] << " ";
            blue << image[r][c][2] << " ";

        }
        red << std::endl;
        green << std::endl;
        blue << std::endl;

        //std::cout << std::endl;
    }
    red.close();
    green.close();
    blue.close();


    //return image; ?

}
