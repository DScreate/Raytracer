//
// Created by Derek on 1/23/2020.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H


#include "../target.h"

template<class T>
class Triangle: Target<T> {
    Intersection<T>& firstIntersectionBetween(Ray<T>& ray, T& tMin, T& tMax) override;
    Vector3<T>& getNormal(Point3<T>& point) override;
};


#endif //RAYTRACER_TRIANGLE_H
