//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Helpers/Space/vector3.h"
#include "Helpers/image.h"

template<class T>
class Ray {
public:
    // r(t) = o + dt
    /*
     * o
     */
    Vector3<T> origin;
    /*
     * d - normalized
     */
    Vector3<T> direction;
    /*
     * t
     */
    T distance;
    T tMin;
    T tMax;
    T refractiveIndex = 1.0f;
    int depth = 0;

    Ray() : origin(), direction(), distance(T(1)), tMin(0), tMax(1000) {};

    Ray(const Vector3<T> &_origin, const Vector3<T> &_direction, const T _distance, const T _tMin = 0,
        const T _tMax = 1000, const T _refractiveIndex = 1, const T _depth = 0) :
            origin(_origin), direction(_direction), distance(_distance), tMin(_tMin), tMax(_tMax),
            refractiveIndex(_refractiveIndex), depth(_depth) {};

    T refractionRate() const;
};

template<class T>
T Ray<T>::refractionRate() const {
    return 1.0f / refractiveIndex;
}


#endif //RAYTRACER_RAY_H
