//
// Created by Derek on 1/23/2020.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H


#include "../target.h"

template<class T>
class Triangle: public Target<T> {
    Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const override;
    Vector3<T> getNormal(const Vector3<T>& point) const override;
};

//TODO: Finish this
template<class T>
Intersection<T> Triangle<T>::firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const {
    return Intersection<T>();
}

template<class T>
Vector3<T> Triangle<T>::getNormal(const Vector3<T> &point) const {
    return Vector3<T>();
}

#endif //RAYTRACER_TRIANGLE_H
