//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H

template<class T>
class RGB {
public:
    T r;
    T g;
    T b;

    RGB() : r(255), g(255), b(255) {};
    RGB(T _r, T _g, T _b) : r(_r), g(_g), b(_b) {};

    RGB& operator+=(const RGB& that);
    RGB& operator-=(const RGB& that);
    RGB& operator*=(const RGB& that);
    RGB& operator*=(const T& factor);
    RGB& operator/=(const T& factor);
};


#endif //RAYTRACER_RGB_H
