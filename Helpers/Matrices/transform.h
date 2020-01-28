//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_TRANSFORM_H
#define RAYTRACER_TRANSFORM_H

/*
 * 4x4 Transform for general purpose use
 * General design sourced from
 * "Fundamentals of Computer Graphics, 4th Edition" by Steve Marschner and Peter Shirley
 * pp. 9 & Ch. 6
 */
template<class T>
class Transform {
    public:

    T components[4][4];
    Transform<T>& operator*=(Transform<T>& that);
};


#endif //RAYTRACER_TRANSFORM_H
