//
// Created by Derek on 2/10/2020.
//

#ifndef RAYTRACER_RGBA_H
#define RAYTRACER_RGBA_H

#include "rgb.h"

template<class T>
class RGBA : public RGB<T> {
    T a;

};

#endif //RAYTRACER_RGBA_H
