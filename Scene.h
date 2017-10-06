#ifndef SCENE_H
#define SCENE_H

#include "Triangle.h"
#include <iostream>


// The scene is always a hexagon room
class Scene{
public:
    //different colors for the walls, white floor and ceiling
    void getIntersection(Ray& ray);

    ColorDbl white{1,1,1};
    ColorDbl w1{1,0,0}; //red
    ColorDbl w2{1,1,0}; //yellow
    ColorDbl w3{0,1,1}; //cyan
    ColorDbl w4{0,0,1}; //blue
    ColorDbl w5{1,0,1}; //magenta
    ColorDbl w6{0,1,0}; //green

    //list of all vertices
    Vertex v[12]{
        Vertex(-3,0,5,0), //top 0-5
        Vertex(0,6,5,0),
        Vertex(10,6,5,0),
        Vertex(13,0,5,0),
        Vertex(10,-6,5,0),
        Vertex(0,-6,5,0),

        Vertex(-3,0,-5,0), //bottom 6-11
        Vertex(0,6,-5,0),
        Vertex(10,6,-5,0),
        Vertex(13,0,-5,0),
        Vertex(10,-6,-5,0),
        Vertex(0,-6,-5,0)
    };

    const static int T_SIZE = 20;
    Triangle triangles[T_SIZE]{

        Triangle(v[2], v[0],  v[1],white),   //top 0-3
        Triangle(v[4], v[2], v[3],white),
        Triangle(v[5], v[0], v[4],white),
        Triangle(v[4], v[0], v[2],white),

        Triangle(v[11], v[10], v[6],white), //bottom 4-7
        Triangle(v[9], v[8], v[10],white),
        Triangle(v[7], v[6], v[8],white),
        Triangle(v[8], v[6], v[10],white),

        Triangle(v[1], v[0], v[7], w1),      //red wall
        Triangle(v[7], v[0], v[6], w1),
        Triangle(v[2], v[1], v[8], w2),      //yellow wall
        Triangle(v[8], v[1], v[7], w2),
        Triangle(v[3], v[2], v[9], w3),      //cyan wall
        Triangle(v[9], v[2], v[8], w3),
        Triangle(v[4], v[3], v[10], w4),     //blue wall
        Triangle(v[10], v[3], v[9], w4),
        Triangle(v[5], v[4], v[11], w5),     //magenta wall
        Triangle(v[11], v[4], v[10], w5),
        Triangle(v[0], v[5], v[6], w6),      //green wall
        Triangle(v[6], v[5], v[11], w6)
    };
};

#endif // SCENE_H
