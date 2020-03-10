
#ifndef RAYTRACER_PLANETOID_H
#define RAYTRACER_PLANETOID_H

#include "./sphere.h"
#include "../perlin_lewis/perlin.h"
#include "../intersection.h"

template<class T>
class Planetoid : public Target {
public:
    Vector3<T> center;
    T radius;
    Vector3<T> northVector = Vector3<T>(0, 1, 0);

    Planetoid() : center(Vector3<T>(T(0), T(0), T(0))), radius(T(1)) {};

    Planetoid(const Vector3<T> &_center, const T &_radius) : radius(_radius), center(_center) {};

    Vector3<T> getNormal(const Vector3<T> &point) const override;

    Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const;

    void move(T timeSpan);

    T getLatitude(const Vector3<T> &pointOnSurface) const;
};

template<class T>
Vector3<T> Planetoid<T>::getNormal(const Vector3<T> &point) const {
    double values[3] = {double(point.x), double(point.y), double(point.z)};
    return (point - center);// * noise(values, 3);
}


template<class T>
Intersection<T> Planetoid<T>::firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const {
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
    auto As = ray.direction.Dot(ray.direction); // should be 1
    auto Bs = 2 * ray.direction.Dot(L);
    auto Cs = L.Dot(L) - pow(radius, 2);
    auto discriminant = pow(Bs, 2) - 4 * As * Cs;
    if (discriminant < 0) {
        res.hit = false;
        return res;
    }


    if (discriminant > 0) {
        T plusT = (-Bs + sqrt(discriminant)) / (2 * As);
        T minusT = (-Bs - sqrt(discriminant)) / (2 * As);
        // two roots
        res.tMin = std::min(plusT, minusT);
        res.tMax = std::max(plusT, minusT);
    } else { // if discriminant == 0
        // one root
        res.tMin = -(Bs / (2 * As));
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

    double values[3] = {double(res.point.x), double(res.point.y), double(res.point.z)};
    double noiseValue = noise(values, 3);
    //res.point += getNormal(res.point) * ((noiseValue + 1) / 2 )* 100.;
    //res.point += getNormal(res.point) * 20.;
    res.hit = true;
    return res;
}

template<class T>
void Planetoid<T>::move(T timeSpan) {
    center += (velocity * timeSpan);
}

template<class T>
T Planetoid<T>::getLatitude(const Vector3<T> &pointOnSurface) const {
    //return (pointOnSurface.y) * 180.0 / M_PI;
    Vector3<T> dir = getNormal(pointOnSurface);
    Vector3<T> horz = Vector3<T>(dir.x, 0, dir.z);

    T res = acos(horz.Orthonormal().Dot(dir.Orthonormal()) /
                 (horz.Orthonormal().Magnitude() * dir.Orthonormal().Magnitude())) * 180 / M_PI;
    //std::cout << res << std::endl;
    return res;

}

#endif //RAYTRACER_PLANETOID_H
