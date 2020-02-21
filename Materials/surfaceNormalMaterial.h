#include "material.h"
#include "../Helpers/rgb.h"
#include "../ray.h"
#include "../intersection.h"

#ifndef RAYTRACER_BASICMATERIAL_H
#define RAYTRACER_BASICMATERIAL_H

#endif //RAYTRACER_BASICMATERIAL_H

template<class T>
class SurfaceNormalMaterial : public Material<T> {
public:

    SurfaceNormalMaterial<T>() {};

    Color illuminate(const Intersection<T> &_intersection, const Ray<T> &_ray, const Scene<T> &_scene) const override;

};

template<class T>
Color
SurfaceNormalMaterial<T>::illuminate(const Intersection<T> &_intersection, const Ray<T> &_ray,
                                     const Scene<T> &_scene) const {
    Vector3<T> normal = _intersection.getNormal();

    return ColorMake(_ray.direction.x, _ray.direction.y, _ray.direction.z);
}
