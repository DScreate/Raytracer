//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include <memory>
#include "ray.h"
#include "radiance.h"
#include "intersection.h"
#include "target.h"

using std::vector;

template<class T>
class Scene {
public:

    vector<std::unique_ptr<Target<T>>> targets;
    RGB<T> backgroundColor;


    Scene() : targets(), backgroundColor(102, 204, 255) {};
    Scene(const RGB<T> &_backgroundColor) : targets(), backgroundColor(_backgroundColor) {};
    //Scene(vector<Target<T>> _targets) : targets(_targets) {};


    void addTarget(Target<T> _target);
    Radiance<T> traceRay(const Ray<T> &ray, const T &tMin);
    Intersection<T> firstIntersection(const Ray<T> &ray, const T& tMin);
};

template<class T>
Radiance<T> Scene<T>::traceRay(const Ray<T> &ray, const T &tMin) {
    return Radiance<T>();
}


template<class T>
void Scene<T>::addTarget(Target<T> _target) {
    targets.push_back(std::make_unique(_target));
}

template<class T>
Intersection<T> Scene<T>::firstIntersection(const Ray<T> &ray, const T &tMin) {
    return Intersection<T>();
}


#endif //RAYTRACER_SCENE_H
