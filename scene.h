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
#include "Lighting/luminaire.h"

using std::vector;

template<class T>
class Scene {
public:

    vector<std::shared_ptr<Target>> targets;
    vector<Luminaire<T> *> luminaires;
    Color backgroundRadiance;
    T ambientRefractiveIndex = T(1.);
    int maxRayDistance = 100000;

    Scene() : backgroundRadiance(0, 0, 0) {};

    Scene(const RGB<T> &_backgroundColor) : backgroundRadiance(_backgroundColor) {};
    //Scene(vector<Target<T>> _targets) : targets(_targets) {};


    //void addTarget(Target<T> &_target);
    Color traceRay(const Ray<T> &ray, const T &tMin);

    Intersection<T> firstIntersection(const Ray<T> &ray, const T &tMin) const;
};

template<class T>
Color Scene<T>::traceRay(const Ray<T> &ray, const T &tMin) {

    if (ray.depth > MAX_RAY_DEPTH) {
        return Color(0, 0, 0);
    }

    Intersection<T> intersection = firstIntersection(ray, tMin);

    Color result = Color();
    if (intersection.hit) {
        for (Material<T> *material : intersection.target->material) {
            result += material->illuminate(intersection, ray, *this);
        }
        return result;
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

// TODO: Double check this on conforming to Dr. Lewis' slide? We may be continuing on with the Ray intersection when we don't need to
template<class T>
Intersection<T> Scene<T>::firstIntersection(const Ray<T> &ray, const T &tMin) const {
    int tMax = maxRayDistance;
    Intersection<T> candidate = Intersection<T>();
    Intersection<T> intersection;
    candidate.tMin = maxRayDistance;
    for (auto const &item : this->targets) {
        intersection = item->firstIntersectionBetween(ray, tMin, tMax);
        if (intersection.hit && intersection.tMin < candidate.tMin) {
            candidate = intersection;
        }
    }
    return candidate;
}


#endif //RAYTRACER_SCENE_H
