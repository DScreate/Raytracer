//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_TARGET_H
#define RAYTRACER_TARGET_H


#include "Intersection.h"
#include "ray.h"
#include "Helpers/Space/vector3.h"
#include "Helpers/Space/point3.h"

template<class T>
class Target {
public:
    virtual Intersection firstIntersectionBetween(Ray<T> ray, float tMin, float tMax);
    virtual Vector3<T> getNormal(Point3 point);
};


#endif //RAYTRACER_TARGET_H
