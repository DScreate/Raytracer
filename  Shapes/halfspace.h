//
// Created by Derek on 1/26/2020.
//

#ifndef RAYTRACER_HALFSPACE_H
#define RAYTRACER_HALFSPACE_H

#include "../target.h"

template<class T>
class Halfspace: Target<T> {
    Intersection<T>& firstIntersectionBetween(Ray<T>& ray, T& tMin, T& tMax) override;
    Vector3<T>& getNormal(Point3<T>& point) override;
};


#endif //RAYTRACER_HALFSPACE_H
