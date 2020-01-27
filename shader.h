//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_SHADER_H
#define RAYTRACER_SHADER_H


#include "radiance.h"
#include "Intersection.h"
#include "ray.h"
#include "luminaire.h"

template<class T>
class Shader {
    Radiance<T> directRadiance(Shader shader, Intersection intersection, Ray<T> incidentRay, Luminaire<T> luminaire);
};


#endif //RAYTRACER_SHADER_H
