//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H

#include <iostream>


template<class T>
class RGB {
public:
    int r;
    int g;
    int b;

    RGB() : r(255), g(255), b(255) {};

    RGB(const int &_r, const int &_g, const int &_b) : r(_r), g(_g), b(_b) {};

    RGB &operator+=(const RGB &that);

    RGB &operator-=(const RGB &that);

    RGB &operator*=(const RGB &that);

    RGB &operator*=(const T &factor);

    RGB &operator/=(const T &factor);
};

template<class T>
RGB<T> &RGB<T>::operator+=(const RGB &that) {
    this->r = (this->r + that.r) / 2;
    this->g = (this->g + that.g) / 2;
    this->b = (this->b + that.b) / 2;
    return *this;
}

template<class T>
RGB<T> &RGB<T>::operator*=(const T &factor) {
    std::cout << "Factor is " << factor << std::endl;
    std::cout << "R is " << this->r << std::endl;

    this->r = this->r * abs(factor);
    std::cout << "R is " << this->r << std::endl;

    this->g = this->g * abs(factor);
    this->b = this->b * abs(factor);
    return *this;
}

template<class T>
RGB<T> operator+(const RGB<T> &Left, const RGB<T> &Right) {
    RGB<T> res = Left;
    return res += Right;
}

template<class T>
RGB<T> operator*(const RGB<T> &Left, const T &Right) {
    RGB<T> res = Left;
    return res *= Right;
}

typedef RGB<float> Color;

#endif //RAYTRACER_RGB_H
