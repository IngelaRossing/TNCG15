#ifndef CAMERA_H
#define CAMERA_H

#include "Scene.h"
#include "Pixel.h"
#include <vector>
#include <array>

class Camera{

     Vertex eyes[2]{Vertex(-1,0,0,0),Vertex(-2,0,0,0)};
     int eye = 1; //let the user choose which eye to use, 0 or 1, default is 0

    Scene scene;

    static const int WINDOW_SIZE = 5;
    //std::vector<std::vector<Pixel>> window;
    std::array<std::array<Pixel, WINDOW_SIZE>, WINDOW_SIZE> pixels;


public:
    void render(); //launches a ray through each pixel one at a time and changes pixel color
    void createImage();
   // Camera(int e);
};

#endif // CAMERA_H
