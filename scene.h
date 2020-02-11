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
#include "Shapes/sphere.h"
#include "Helpers/typedefs.h"

using std::vector;
typedef ATarget<float> Target;

template<class T>
class Scene {
public:

    vector<Target *> targets;
    Color backgroundRadiance;

    int maxRayDistance = 1000;

    Scene() : backgroundRadiance(0, 0, 0) {};

    Scene(const RGB<T> &_backgroundColor) : backgroundRadiance(_backgroundColor) {};
    //Scene(vector<Target<T>> _targets) : targets(_targets) {};


    //void addTarget(Target<T> &_target);
    Color traceRay(const Ray<T> &ray, const T &tMin);

    Intersection<T> firstIntersection(const Ray<T> &ray, const T &tMin);
};

template<class T>
Color Scene<T>::traceRay(const Ray<T> &ray, const T &tMin) {

    Intersection<T> intersection = firstIntersection(ray, tMin);

    if (intersection.hit) {
        return intersection.target->material->illuminate();
    }
    return backgroundRadiance;
}

template<class T>
Color traceRay(const Scene<T> &scene, const Ray<T> &ray, const T &tMin) {
    return scene.traceRay(ray, tMin);
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
    for (const auto &item : this->targets) {
        Intersection<T> intersection = item->firstIntersectionBetween(ray, tMin, tMax);
        if (intersection.hit) {
            return intersection;
        }
    }
    return Intersection<T>();
}


#endif //RAYTRACER_SCENE_H
