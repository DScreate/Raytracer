//
// Created by tessa on 2/10/20.
//

#ifndef RAYTRACER_SHADER_H
#define RAYTRACER_SHADER_H

#include "material.h"
#include "../Lighting/luminaire.h"
#include "../Helpers/rgb.h"
#include "../Helpers/Space/vector3.h"
#include "../ray.h"
#include "../intersection.h"
#include "../scene.h"

template<class T>
class Shader : public Material<T> {
public:
    Color illuminate(const Intersection<T> &_intersection, const Ray<T> &_ray, const Scene<T> &_scene) const override;

    Color directRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Luminaire<T> _luminaire) const;

    virtual Color brdf(Vector3<T> _towardsLuminaire, Vector3<T> _normal, Vector3<T> _towardsCamera) const = 0;
};

template<class T>
Color Shader<T>::directRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Luminaire<T> _luminaire) const {

    Vector3<T> towardsCamera = _incidentRay.direction.Orthonormal() * -1;
    Vector3<T> normal = _intersection.point.Orthonormal();
    Vector3<T> towardsLuminaire = _luminaire.towards(_intersection.point);
    return (brdf(towardsLuminaire, normal, towardsCamera) * _luminaire.radiantFlux *
            normal.Orthonormal().Dot(towardsLuminaire.Orthonormal()));
}

template<class T>
Color Shader<T>::illuminate(const Intersection<T> &_intersection, const Ray<T> &_ray, const Scene<T> &_scene) const {
    Color color = Color();
    for (auto &luminaire : _scene.luminaires) {
        color += this->directRadiance(_intersection, _ray, *luminaire);
    }
    return color;
}

#endif //RAYTRACER_SHADER_H
