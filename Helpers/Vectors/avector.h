//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_AVECTOR_H
#define RAYTRACER_AVECTOR_H


class avector {
    public:
        virtual ~avector();
        virtual avector& operator+(const avector& that);
        // subtraction
        virtual avector& operator-(const avector& that);
        // dot product
        virtual float dot(const avector& that);
        // cross product
        virtual avector& cross(const avector& that);
        // scalar multiplication
        virtual avector& operator*=(float factor);
        // scalar division
        virtual avector& operator/=(float factor);
};


#endif //RAYTRACER_AVECTOR_H
