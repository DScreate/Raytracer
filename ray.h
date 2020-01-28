//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Helpers/Space/point3.h"
#include "Helpers/Space/vector3.h"

template<class T>
class Ray {

    // r(t) = o + dt
    /*
     * o
     */
    Point3<T> origin;
    /*
     * d - normalized
     */
    Vector3<T> direction;
    /*
     * t
     */
    T distance;
};


#endif //RAYTRACER_RAY_H
