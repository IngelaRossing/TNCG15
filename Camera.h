#ifndef CAMERA_H
#define CAMERA_H

#include "Scene.h"
#include "Pixel.h"
#include <vector>
#include <array>

class Camera{
    Vertex eye1{-1,0,0,0};
    Vertex eye2{-2,0,0,0};
    int WINDOW_SIZE = 100;
    //std::vector<std::vector<Pixel>> window;
    std::array<std::array<Pixel, 100>, 100> pixels;
    int eye = 1; //let the user choose which eye to use, can be one or two, default is one

public:
    void render(); //launches a ray through each pixel one at a time and changes pixel color
    void createImage();
   // Camera(int e);
};

#endif // CAMERA_H
