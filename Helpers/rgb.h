//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H


class rgb {
public:
    float r;
    float g;
    float b;

    rgb operator+=(rgb that);
    rgb operator-=(rgb that);
    rgb operator*=(rgb that);
    rgb operator*=(float factor);
    rgb operator/=(float factor);
};


#endif //RAYTRACER_RGB_H
