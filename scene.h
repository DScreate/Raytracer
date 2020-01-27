//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "ray.h"
#include "radiance.h"
#include "Intersection.h"

template<class T>
class Scene {
    Radiance<T> traceRay(Scene<T> scene, Ray<T> ray, float tMin);
    Intersection firstIntersection(Scene<T> scene, Ray<T> ray, float tMin);
};


#endif //RAYTRACER_SCENE_H
