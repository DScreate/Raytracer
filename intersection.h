//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H

template<class T>
class Intersection {
public:
    T tMin;
    T tMax;
    int numHits;
    Intersection<T>(): tMin(T(0)), tMax(T(0)), numHits(0) {}
    Intersection<T>(const T &_tMin, const T &_tMax, const int &_numHits) : tMin(_tMin), tMax(_tMax), numHits(_numHits) {}
};


#endif //RAYTRACER_INTERSECTION_H
