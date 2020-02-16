//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H

#include <algorithm>
#include <iostream>
#include <cmath>
#include "Space/vector3.h"

// radiance watts/m^2 something
// radiance has red green and blue components
// but RGB has dimensionless value, has no units
// radiance should be between 0 and 1
// map 0 to 1 to 0 to 255, if > 1 then put out an error message

template<class T>
class RGB {
public:
    T r;
    T g;
    T b;

    RGB() : r(T(0)), g(T(0)), b(T(0)) {};

    RGB(const T &_r, const T &_g, const T &_b) : r(_r), g(_g), b(_b) {};

    RGB &operator+=(const RGB &that);

    RGB &operator-=(const RGB &that);

    RGB &operator*=(const RGB &that);

    RGB &operator*=(const T &factor);

    RGB &operator/=(const T &factor);
};

template<typename T>
T clip(const T &n, const T &lower, const T &upper) {
    return std::max(lower, std::min(n, upper));
}


template<class T>
RGB<T> &RGB<T>::operator+=(const RGB &that) {
    this->r = clip((this->r + that.r), T(0), T(1));
    this->g = clip((this->g + that.g), T(0), T(1));
    this->b = clip((this->b + that.b), T(0), T(1));
    return *this;
}

template<class T>
RGB<T> &RGB<T>::operator*=(const T &factor) {
    /*
    this->r = std::clamp(int(this->r * fabs(factor)), 0,0); 1);
    this->g = std::clamp(int(this->g * fabs(factor)), 0, 1);
    this->b = std::clamp(int(this->b * fabs(factor)), 0, 1);\
     */

    this->r = (this->r * factor);// / 2;
    this->g = (this->g * factor);// / 2;
    this->b = (this->b * factor);
    return *this;
}

template<class T>
RGB<T> &RGB<T>::operator*=(const RGB &that) {
    this->r = (this->r * that.r);
    this->g = (this->g * that.g);
    this->b = (this->b * that.b);
    return *this;
}

template<class T>
RGB<T> &RGB<T>::operator/=(const T &factor) {
    this->r = (this->r / factor);// / 2;
    this->g = (this->g / factor);// / 2;
    this->b = (this->b / factor);
    return *this;
}

template<class T>
RGB<T> operator+(const RGB<T> &Left, const RGB<T> &Right) {
    RGB<T> res = Left;
    return res += Right;
}

template<class T>
RGB<T> operator*(const RGB<T> &Left, const RGB<T> &Right) {
    RGB<T> res = Left;
    return res *= Right;
}

template<class T>
RGB<T> operator*(const RGB<T> &Left, const T &Right) {
    RGB<T> res = Left;
    return res *= Right;
}

template<class T>
RGB<T> operator/(const RGB<T> &Left, const T &Right) {
    RGB<T> res = Left;
    return res /= Right;
}


template<class T>
RGB<T> operator/(const RGB<T> &Left, const int &Right) {
    RGB<T> res = Left;
    return res /= Right;
}


template<class T>
RGB<T> ColorMake(const T &x, const T &y, const T &z) {
    RGB<T> temp;
    temp.r = T((0.5f * (x + 1.0f)));
    temp.g = T((0.5f * (y + 1.0f)));
    temp.b = T((0.5f * (z + 1.0f)));

    return temp;
}


typedef RGB<double> Color;

#endif //RAYTRACER_RGB_H
