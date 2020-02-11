//
// Created by tessa on 2/10/20.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


template<class T>
class Intersection;

template<class T>
class Scene;

template<class T>
class Material {
public:
    virtual Color
    illuminate(const Intersection<T> &_intersection, const Ray<T> &_ray, const Scene<T> &_scene) const = 0;
    //virtual Color illuminate() = 0;
};

#endif //RAYTRACER_MATERIAL_H
