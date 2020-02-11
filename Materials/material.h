//
// Created by tessa on 2/10/20.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "../Helpers/typedefs.h"

template<class T>
class Material {
public:
    //virtual Color illuminate(const Intersection<T> &_intersection, const Ray<T> &_ray, const Scene<T> &_scene) = 0;
    virtual Color illuminate();
};

#endif //RAYTRACER_MATERIAL_H
