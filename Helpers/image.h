//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include "rgb.h"

/*
 * Image class for display pixel data
 * General design sourced from
 * "Fundamentals of Computer Graphics, 4th Edition" by Steve Marschner and Peter Shirley
 * pp. 9
 */
template<class T>
class Image {
public:
    // TODO: Convert this to a flexible sized container?
    RGB<T> pixels[256][256];

    Image(): RGB<T>(RGB<T>() = {}) {};


    void output();
};


#endif //RAYTRACER_IMAGE_H
