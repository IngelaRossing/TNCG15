#ifndef CAMERA_H
#define CAMERA_H

#include "Scene.h"
#include "Pixel.h"
#include "Sphere.h"
#include <vector>
#include <array>
#include <fstream> //write to a file

//#include "CImg.h" //does not find a file included in CImg.h

class Camera{

    Vertex eyes[2]{Vertex(-1,0,0,0),Vertex(-2,0,0,0)};
    int eye = 0; //let the user choose which eye to use, 0 or 1, default is 0

    Scene scene;

    static const int WINDOW_SIZE = 100; //Don't know why it doesn't run for bigger size :(
    //std::vector<std::vector<Pixel>> window;
    std::array<std::array<Pixel, WINDOW_SIZE>, WINDOW_SIZE> pixels;

    ColorDbl castRay(Ray &ray, int depth);

public:
    void render(); //launches a ray through each pixel one at a time and changes pixel color
    void createImage(); //Convert pixel data to 2D array of rgb-vectors     SHOULD IT RETURN A POINTER TO ARRAY?
   // Camera(int e);
};

#endif // CAMERA_H
