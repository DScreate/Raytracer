//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H


class Vector3 {
public:
    // x,y, z component
    float x;
    float y;
    float z;
    // length-n array
    int Components[3];
    // addition
    Vector3& operator+(const Vector3& that);
    // subtraction
    Vector3& operator-(const Vector3& that);
    // dot product
    float dot(const Vector3& that);
    // cross product
    Vector3& cross(const Vector3& that);
    // scalar multiplication
    Vector3& operator*=(float factor);
    // scalar division
    Vector3& operator/=(float factor);
};


#endif //RAYTRACER_VECTOR3_H
