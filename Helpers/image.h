//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include <vector>
#include "rgb.h"

class image {
public:
    image();
    ~image();

    std::vector<std::vector<rgb>> pixels;

    void output();
};


#endif //RAYTRACER_IMAGE_H
