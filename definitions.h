#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

#include "glm/glm.hpp"
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <iostream>

using Vertex = glm::vec4; //three spatial coordinates x,y,z and w for homogeneous coordinates
using Direction =glm::vec3; //direction vector (x,y,z)
using ColorDbl = glm::dvec3; //double[3]; //three double prec. variables for RGB intensities
using ivec3 = std::array<int,3>; // for storing int color values

enum surfaceType{
    diffuse, specular, lightSource
};




#endif // DEFINITIONS_H_INCLUDED
