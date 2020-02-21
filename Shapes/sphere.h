#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include <algorithm>
#include "../target.h"

template<class T>
class Sphere : public Target {
public:
    Vector3<T> center;
    T radius;

    Sphere() : center(Vector3<T>(T(0), T(0), T(0))), radius(T(1)) {};

    Sphere(const Vector3<T> &_center, const T &_radius) : radius(_radius), center(_center) {};

    /*
     * center c = (xc, yc, zc) and radius R can be represented by the implicit equation
     * (x - xc)^2 + (y - yc)^2 + (z - zc)^2 - R^2 = 0
     * vector form:
     * (p_ - c_) * (p_ - c_) - R^2 = 0
     * n_ denotes "vector n"
     */
    Vector3<T> getNormal(const Vector3<T> &point) const;

    Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const;
};

template<class T>
Intersection<T> Sphere<T>::firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const {
    Intersection<T> res = Intersection<T>(tMin, tMax, false);
    // a sphere with center c~ = (xc, yc, zc) and radius R
    // can also be written as (p~ - c~) - (p~ - c~) - R^2 = 0
    // If we plug points on the ray p~(t) = e~ + td~
    // we get:
    // (e~ + td~ - c~) * (e~ + td~ - c~) - R^2 = 0
    // Remember: e is the ray's origin and t is the distance.
    // d is also (s - e) aka direction
    // A = 1;
    // B = 2(d_ * (o - c));
    // C = abs(o - c)^2 - R^2);
    // t = {-B +- root(B^2 - 4AC)} / 2A

    // first check if discriminant is negative
    // if so, ray and object do not intersect
    Vector3<T> L = (ray.origin - center);
    auto A = ray.direction.Dot(ray.direction); // should be 1
    auto B = 2 * ray.direction.Dot(L);
    auto C = L.Dot(L) - pow(radius, 2);
    auto discriminant = pow(B, 2) - 4 * A * C;
    if (discriminant < 0) {
        res.hit = false;
        return res;
    }


    if (discriminant > 0) {
        T plusT = (-B + sqrt(discriminant)) / (2 * A);
        T minusT = (-B - sqrt(discriminant)) / (2 * A);
        // two roots
        res.tMin = std::min(plusT, minusT);
        res.tMax = std::max(plusT, minusT);
    } else { // if discriminant == 0
        // one root
        res.tMin = -(B / (2 * A));
    }

    if (res.tMin < 0) {
        res.tMin = res.tMax;
    }


    if (res.tMin < tMin || res.tMin > tMax) {
        return res;
    }

    Vector3<T> adjustment = ray.direction.Orthonormal() * EPSILON;
    res.point = ray.origin - adjustment + ray.direction * res.tMin;
    res.target = this;

    res.hit = true;
    return res;
}

template<class T>
Vector3<T> Sphere<T>::getNormal(const Vector3<T> &point) const {
    return (point - center);
}

#endif //RAYTRACER_SPHERE_H
