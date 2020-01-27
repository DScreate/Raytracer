//
// Created by Derek on 1/23/2020.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "../target.h"

template<class T>
class Sphere: Target<T> {
public:
    Point3<T> center;
    T radius;

    Sphere(): center(Point3<T>(T(0), T(0), T(0))), radius(T(0)) {};
    Sphere(const Point3<T>& _center, T _radius) : radius(_radius), center(_center) {};
    /*
     * center c = (xc, yc, zc) and radius R can be represented by the implicit equation
     * (x - xc)^2 + (y - yc)^2 + (z - zc)^2 - R^2 = 0
     * vector form:
     * (p_ - c_) * (p_ - c_) - R^2 = 0
     * n_ denotes "vector n"
     */

    Intersection<T>& firstIntersectionBetween(Ray<T>& ray, T& tMin, T& tMax) override;
    Vector3<T>& getNormal(Point3<T>& point) override;
    bool DoesIntersect(Ray<T>& ray);
};


#endif //RAYTRACER_SPHERE_H
