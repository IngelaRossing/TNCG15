#include "Camera.h"

void Camera::render(Scene &scene){

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

            Vertex ps = eyes[eye]; //user chooses wich eye to use with variable eye

            glm::vec4 D = glm::normalize( px - ps) * 1000.0f; //a vector D with length 30, intersecting pixel on its way to the eye
           // std::cout << "D: " << D.x << D.y << D.z << " ";

            Vertex pe =  ps + D; //endpoint   //Vertex(pe.x-*D.x, pe.y-*D.y, pe.z-*D.z, 0);
            //std::cout << "ps: " << ps.x << "," << ps.y << ","<< ps.z << " \n";
            //We create a white ray with end point somewhere far in the direction D from eye point
            Ray * ray = new Ray( ps , pe, ColorDbl(1,1,1) ); //NOTE: ray could be deallocated after function render is done

            //CAST RAY, let it get reflected into the scene

            //find first intersection by checking intersection with all triangles in the scene and save triangle and point in ray
            //scene.getIntersection(*ray); //WILL BE DONE INSIDE castRay LATER


            castRay(*ray, 0, scene); //OBJECT CANT BE SEEN?!

            //DEBUGGING COMMENT: We should be looking directly at triangle 12-15 (blue and cyan wall) within our scene


            pixels[r][c].intersecting_rays.push_back(ray); //Store ray in pixel

        }
        //std::cout << std::endl;
    }
    std::cout << "\n\nIF RAY IN PIXEL:\n\n";
    createImage();
}

//Let a ray spread from ray startingpoint into scene with ray.direction and get its color, which might be dependent on its reflections
ColorDbl Camera::castRay(Ray &ray, int depth, Scene &scene)
{
      // ------ FIND THE RAYS FIRST INTERSECTIONSPOINT ON A SURFACE  ---

    //ray gets updated with info about the first intersection, if hitTriangle doesn't exist first intersection is with a sphere
    scene.getIntersection(ray);
    Surface s{ColorDbl(0,1,0),diffuse}; //default
    Direction normal;

    //If first intersection is with a triangle: if hitTriangle exists
    if(ray.getHitTriangle())
    {
        //We need to know surface properties and its normal
        normal = ray.getHitTriangle()->getNormal();
        s = ray.getHitTriangle()->getSurface();

    }
    else if(ray.getHitSphere()){
        //find sphere normal and surface
        normal = ray.getHitSphere()->getNormal(ray.getEnd());
        s = ray.getHitSphere()->getSurface();
    }
    else //no intersection -> no light to add
    {
        ray.setColor(ColorDbl(0,0,1)); //base case
        normal = Direction(1,0,0);
        std::cout << "No intersection!\n";
    }



    //ray.setColor(ColorDbl(normal.x+1.0,normal.y+1.0,normal.z+1.0)*0.5);
    double geometric = double(glm::dot( normal, glm::normalize(ray.getDirection()) ));
    geometric = geometric*geometric;
    //ray.setColor(ColorDbl(geometric, geometric,geometric));


    //FOR NOW WHEN ALL ARE DIFFUSE, LATER STEPS WILL BE ADDED LATER
    ray.setColor(s.diffuseReflection() *geometric);//
    return ray.getColor();



    // ------ CALCULATE LOCAL LIGHT CONTRIBUTION ------


    //Most rays don't end up in a lighsource and we use shadow rays to add a local contribution to the ray color
    //ColorDbl LocalLight{0,0,0};
    // Geometric term, tilted surfaces reflect less
    //double geometric = double(fabs(glm::dot(glm::normalize(ray.getDirection()), glm::normalize(normal))));

    //return only local if diffuse surface or lightsorce or MAX_DEPTH
    //for diffuse all incident angles give the same light contribution and the ray is not reflected so we return the color the surface emitts
 /*   if(s.surfaceType == diffuse)
    {
        ray.setColor(s.diffuseReflection()  );
        return;
    }
    else
    {
        std::cout << "odifust!";
        //shadow rays can be added here
    }
*/
    // ------ ADD REFLECED RAY IMPORTANCE -------------

 /*   Direction D = s.reflectRay(ray, normal); //Reflection is dependent on surface properties, but MC-method only returns one possible ray
    Vertex endP = in.getEnd() + Vertex(D.x,D.y,D.z,0.0f);
    Ray out = Ray(in.getEnd(), endP, ColorDbl(0,0,0) );

    //float angle = glm::angle(out.getDirection() - normal); //for geometric term in rendering eq. or inside BRDFthingy?

    //Ratio of reflected radiance to incident irradiance
    ColorDbl BRDF = s.getLightContribution(ray, out, normal); //Amount of light reflected into direction for all color chanels?

    if(max(BRDF) > MIN_LIGHT_CONTRIBUTION ) {
        ColorDbl lightColor = castRay(out, depth + 1 );

        //Color towards eye is dependent on self emittance (and local with shadowrays) and surface-color * color of the first intersection of outgoing ray
        //Rendering eq is used to calculate how much of the light is sent towards eye, dependent on surfaceproperties and geometric
        return LocalLight + BRDF .* lightColor;
    }
    else //base case
        return LocalLight; //only from self emmittance and shadowrays



    //Lambertian BRDF = rho/ pi, where rho is a constant refl. coeff.
    //importance of ray is given by BRDF and color of radiance getting reflected into ray
    //ray->ray_color = elementwise multiplication(BRDF, castRay(ray2, depth + 1));
*/


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
