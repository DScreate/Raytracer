//
// Created by tessa on 1/28/20.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H


#include "target.h"

template<class T>
class Triangle : Target<T> {
    Intersection firstIntersectionBetween(Ray<T> ray, float tMin, float tMax) override;
    Vector3<T> getNormal(Point3 point) override;
};


template<class T>
Intersection Triangle<T>::firstIntersectionBetween(Ray<T> ray, float tMin, float tMax) {
    return Target<T>::firstIntersectionBetween(ray, tMin, tMax);
}

template<class T>
Vector3<T> Triangle<T>::getNormal(Point3 point) {
    return Target<T>::getNormal(point);
}
#endif //RAYTRACER_TRIANGLE_H
