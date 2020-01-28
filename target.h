//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_TARGET_H
#define RAYTRACER_TARGET_H


#include "intersection.h"
#include "ray.h"
#include "Helpers/Space/vector3.h"
#include "Helpers/Space/point3.h"

template<class T>
class Target {
public:
    virtual Intersection<T>& firstIntersectionBetween(Ray<T>& ray, T& tMin, T& tMax);
    virtual Vector3<T>& getNormal(Point3<T>& point);
};


#endif //RAYTRACER_TARGET_H
