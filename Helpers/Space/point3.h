//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_POINT3_H
#define RAYTRACER_POINT3_H

template<class T>
class Point3 {
    T x;
    T y;
    T z;

    Point3() : x(T(0)), y(T(0)), z(T(0)) {};
    Point3(const T& _x, const T& _y, const T& _z) : x(_x), y(_y), z(_z) {};
};


#endif //RAYTRACER_POINT3_H
