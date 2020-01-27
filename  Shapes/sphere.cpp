//
// Created by Derek on 1/23/2020.
//
#include <cstdlib>

#include "sphere.h"
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
Vector3<T>& Sphere<T>::getNormal(Point3<T> &point) {
    return Target::getNormal(point);
}

template<class T>
bool Sphere<T>::DoesIntersect(Ray<T> &ray) {
    // compute vector between ray origin and sphere's center
    Vector3<T> originToCenter = new Vector3<T>(ray.origin.x - this->center.x, ray.origin.y - this->center.y, ray.origin.z - this->center.z);
}
