#include "material.h"
#include "../Helpers/rgb.h"
#include "../ray.h"

#ifndef RAYTRACER_BASICMATERIAL_H
#define RAYTRACER_BASICMATERIAL_H

#endif //RAYTRACER_BASICMATERIAL_H

template<class T>
class BasicMaterial : public Material<T> {
public:
    Color reflectivity;

    BasicMaterial<T>() : reflectivity(255, 255, 255) {};

    Color illuminate(const Intersection<T> &_intersection, const Ray<T> &_ray, const Scene<T> &_scene) const override;

};

template<class T>
Color
BasicMaterial<T>::illuminate(const Intersection<T> &_intersection, const Ray<T> &_ray, const Scene<T> &_scene) const {
    return reflectivity;
}
