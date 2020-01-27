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

    RGB& operator+=(const RGB& that);
    RGB& operator-=(const RGB& that);
    RGB& operator*=(const RGB& that);
    RGB& operator*=(const T& factor);
    RGB& operator/=(const T& factor);
};


#endif //RAYTRACER_RGB_H
