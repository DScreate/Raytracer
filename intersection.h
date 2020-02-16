//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H


#include "target.h"

template<class T>
class Intersection {
public:
    T tMin;
    T tMax;
    Vector3<T> point;
    const Target *target;
    bool hit;

    Intersection<T>() : tMin(T(0)), tMax(T(0)), hit(false), target() {}

    Intersection<T>(const T &_tMin, const T &_tMax, const bool &_hit) : tMin(_tMin), tMax(_tMax), hit(_hit) {}

    Vector3<T> getNormal() const;
};

template<class T>
Vector3<T> Intersection<T>::getNormal() const {
    return target->getNormal(point).Orthonormal();
}


#endif //RAYTRACER_INTERSECTION_H
