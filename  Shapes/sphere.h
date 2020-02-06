//
// Created by Derek on 1/23/2020.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "../target.h"

template<class T>
class Sphere: public Target<T> {
public:
    Vector3<T> center;
    T radius;

    Sphere(): center(Vector3<T>(T(0), T(0), T(0))), radius(T(1)) {};
    Sphere(const Vector3<T> &_center, const T & _radius) : radius(_radius), center(_center) {};
    /*
     * center c = (xc, yc, zc) and radius R can be represented by the implicit equation
     * (x - xc)^2 + (y - yc)^2 + (z - zc)^2 - R^2 = 0
     * vector form:
     * (p_ - c_) * (p_ - c_) - R^2 = 0
     * n_ denotes "vector n"
     */
    //Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const;
    //Vector3<T> getNormal(const Vector3<T> &point) const;
    bool DoesIntersect(const Ray<T>& ray) const;

    // TODO
    Vector3<T> getNormal(const Vector3<T> &point) const {
        return point - center;
    }

    Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const {
        return Intersection<T>();
    }
};

/*
 *
 */
/*
template<class T>
Intersection<T>& Sphere<T>::firstIntersectionBetween(Ray<T> &ray, T &tMin, T &tMax) {
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
    T A = 1;
    T B = 2(ray.direction * (ray.origin - this->center));
    if(B < 0)
        return &Intersection(tMin, tMax, 0);

    T C = abs(ray.origin - this->center)^2 - this->radius^2;

}
 */



template<class T>
bool Sphere<T>::DoesIntersect(const Ray<T> &ray) const {
    // compute vector between ray origin and sphere's center
    Vector3<T> originToCenter = new Vector3<T>(ray.origin.x - this->center.x, ray.origin.y - this->center.y, ray.origin.z - this->center.z);


    // d is also (s - e) aka direction
    // A = 1;
    // B = 2(d_ * (o - c));
    // C = abs(o - c)^2 - R^2);
    // t = {-B +- root(B^2 - 4AC)} / 2A
    return nullptr;
}
#endif //RAYTRACER_SPHERE_H
