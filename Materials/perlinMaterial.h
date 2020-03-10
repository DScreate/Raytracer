//
// Created by tessa on 3/9/20.
//

#ifndef RAYTRACER_PERLINMATERIAL_H
#define RAYTRACER_PERLINMATERIAL_H

#include "./shader.h"
#include "../perlin_lewis/perlin.c"

template<class T>
class PerlinMaterial : public Shader<T> {
public:
    Color reflectivity;

    Color brdf(Vector3<T> &_towardsLuminaire, Vector3<T> &_normal, Vector3<T> &_towardsCamera) const override;

    PerlinMaterial<T>() : reflectivity(0, 0, 0) {};

    Color indirectRadiance(Intersection<T> &_intersection, Ray<T> &_incidentRay, Scene<T> &_scene) const;
};

template<class T>
Color PerlinMaterial<T>::brdf(Vector3<T> &_towardsLuminaire, Vector3<T> &_normal, Vector3<T> &_towardsCamera) const {
    double values[3] = {_normal.x, _normal.y, _normal.z};
    return reflectivity * noise(values, 3);
}

template<class T>
Color
PerlinMaterial<T>::indirectRadiance(Intersection<T> &_intersection, Ray<T> &_incidentRay, Scene<T> &_scene) const {
    return Color();
}

#endif //RAYTRACER_PERLINMATERIAL_H
