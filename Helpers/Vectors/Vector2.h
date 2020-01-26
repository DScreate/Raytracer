//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_VECTOR2_H
#define RAYTRACER_VECTOR2_H


#include "avector.h"

class Vector2 : avector {
    public:
        Vector2(const float x, const float y);
        ~Vector2() override;
        // x,y component
        float x;
        float y;
        // length-n array
        int Components[2];
        // addition
        Vector2& operator+(const Vector2& that) override;
        // subtraction
        Vector2& operator-(const Vector2& that);
        // dot product
        float dot(const Vector2& that);
        // cross product
        Vector2& cross(const Vector2& that);
        // scalar multiplication
        Vector2& operator*=(float factor);
        // scalar division
        Vector2& operator/=(float factor);
};


#endif //RAYTRACER_VECTOR2_H
