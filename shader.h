//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_SHADER_H
#define RAYTRACER_SHADER_H


#include "radiance.h"
#include "intersection.h"
#include "ray.h"
#include "luminaire.h"

template<class T>
class Shader {
    Radiance<T>& directRadiance(const Shader<T> &shader, const Intersection<T> &intersection, const Ray<T> &incidentRay, const Luminaire<T> &luminaire);
};


#endif //RAYTRACER_SHADER_H
