//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_TARGET_H
#define RAYTRACER_TARGET_H


#include "ray.h"
#include "Helpers/Space/vector3.h"
#include "Materials/material.h"

template<class T>
class Intersection;


template<class T>
class ATarget {
public:
    std::vector<Material<T> *> material;

    Vector3<T> velocity = Vector3<T>(0, 0, 0);

    virtual void move(T timeSpan) = 0;

    virtual Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const = 0;

    virtual Vector3<T> getNormal(const Vector3<T> &point) const = 0;
};

typedef ATarget<double> Target;

#endif //RAYTRACER_TARGET_H
