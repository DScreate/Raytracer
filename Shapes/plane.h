//
// Created by Derek on 1/23/2020.
//

#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H


#include "../target.h"

template<class T>
class Plane : public Target {
    Intersection<T> &firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const override;

    Vector3<T> &getNormal(const Vector3<T> &point) const override;
};

template<class T>
Intersection<T> &Plane<T>::firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const {
    return Intersection<T>();
}

template<class T>
Vector3<T> &Plane<T>::getNormal(const Vector3<T> &point) const {
    return Vector3<T>();
}


#endif //RAYTRACER_PLANE_H
