//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H

template<class T>
class RGB {
public:
    int r;
    int g;
    int b;

    RGB() : r(255), g(255), b(255) {};
    RGB(const int &_r, const int &_g, const int &_b) : r(_r), g(_g), b(_b) {};

    RGB operator+=(const RGB &that) const;
    RGB operator-=(const RGB &that) const;
    RGB operator*=(const RGB &that) const;
    RGB operator*=(const T &factor) const;
    RGB operator/=(const T &factor) const;
};


#endif //RAYTRACER_RGB_H
