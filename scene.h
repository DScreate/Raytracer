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
    RGB<T> backgroundRadiance;

    int maxRayDistance = 1000;
    Scene() : targets(), backgroundRadiance(102, 204, 255) {};
    Scene(const RGB<T> &_backgroundColor) : targets(), backgroundRadiance(_backgroundColor) {};
    //Scene(vector<Target<T>> _targets) : targets(_targets) {};


    //void addTarget(Target<T> &_target);
    RGB<T> traceRay(const Ray<T> &ray, const T &tMin);
    Intersection<T> firstIntersection(const Ray<T> &ray, const T& tMin);
};

template<class T>
RGB<T> Scene<T>::traceRay(const Ray<T> &ray, const T &tMin) {
    Intersection<T> intersection = scene.firstIntersection(ray, tMin);
    if (intersection.numHits > 0) {
        return intersection.target.material.illuminate(intersection, ray, scene);
    } else {
        return this->backgroundRadiance;
    }
}

// TODO: Implement this so we do not have to create unique pointer in main
/*
template<class T>
void Scene<T>::addTarget(Target<T> &_target) {
    targets.push_back(std::make_unique(_target));
}
 */

template<class T>
Intersection<T> Scene<T>::firstIntersection(const Ray<T> &ray, const T &tMin) {
    int tMax = maxRayDistance;
    Intersection<T> intersection();
    for (Target<T> target : this->targets) {
        Intersection<T> newIntersection = target.firstIntersectionBetween(ray, tMin, tMax);
        if (newIntersection.numHits > 0) {
            intersection = newIntersection;
        }
    }

    return intersection;
}


#endif //RAYTRACER_SCENE_H
