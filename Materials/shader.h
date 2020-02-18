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
#include "../constants.h"

template<class T>
class Shader : public Material<T> {
public:
    T specularExponent = 250.;
    T Ks = 0.2;
    T Kd = 0.3;

    Color
    illuminate(const Intersection<T> &_intersection, const Ray<T> &_incidentRay, const Scene<T> &_scene) const override;

    Color directRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Luminaire<T> _luminaire) const;

    virtual Color
    indirectRadiance(const Intersection<T> &_intersection, const Ray<T> &_incidentRay, const Scene<T> &_scene) const;

    virtual Color brdf(Vector3<T> &_towardsLuminaire, Vector3<T> &_normal, Vector3<T> &_towardsCamera) const = 0;

    Color specular(const Intersection<T> &_intersection, const Ray<T> &_incidentRay, Luminaire<T> _luminaire) const;
};

/*
 * Light that shines directly
 */
// TODO: Convert these to be const refs
template<class T>
Color Shader<T>::directRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Luminaire<T> _luminaire) const {

    Vector3<T> towardsCamera = _incidentRay.direction.Orthonormal() * -1;
    Vector3<T> normal = _intersection.getNormal().Orthonormal();
    Vector3<T> towardsLuminaire = (_luminaire.towardsLum(_intersection.point)).Orthonormal();
    auto tempDot = std::max(T(0), normal.Dot(towardsLuminaire));
    return ((brdf(towardsLuminaire, normal, towardsCamera) / PI) * _luminaire.irradiance(_intersection.point, normal));
}

template<class T>
Color
Shader<T>::illuminate(const Intersection<T> &_intersection, const Ray<T> &_incidentRay, const Scene<T> &_scene) const {
    Color color = Color();

    color += indirectRadiance(_intersection, _incidentRay, _scene);
    Vector3<T> towardsCamera = _incidentRay.direction * -1;
    Vector3<T> point = _intersection.point;
    Vector3<T> normal = _intersection.getNormal();
    Vector3<T> towardsLuminaire;
    for (auto const &luminaire : _scene.luminaires) {
        towardsLuminaire = luminaire->towardsLum(point).Orthonormal();
        auto temp = normal.Dot(towardsLuminaire);
        if (normal.Dot(towardsLuminaire) > 0) { // above horizon
            auto shadowRay = Ray<T>(point, towardsLuminaire, 1, 0, _scene.maxRayDistance, _incidentRay.refractiveIndex,
                                    _incidentRay.depth + 1);
            Intersection<T> shadowIntersection = _scene.firstIntersection(shadowRay, EPSILON);
            if (!shadowIntersection.hit || luminaire->isBetween(shadowIntersection.point, point, shadowRay)) {
                color += directRadiance(_intersection, _incidentRay, *luminaire) * Kd +
                         specular(_intersection, _incidentRay, *luminaire) * Ks;
            }
        }
    }
    return color;
}

template<class T>
Color Shader<T>::indirectRadiance(const Intersection<T> &_intersection, const Ray<T> &_incidentRay,
                                  const Scene<T> &_scene) const {
    return Color();
}

template<class T>
Color
Shader<T>::specular(const Intersection<T> &_intersection, const Ray<T> &_incidentRay, Luminaire<T> _luminaire) const {
    Vector3<T> towardsCamera = _incidentRay.direction * -1;
    Vector3<T> L = _luminaire.towardsLum(_intersection.point).Orthonormal();
    Vector3<T> normal = _intersection.getNormal();
    Vector3<T> R = normal * normal.Dot(L) * 2 - L;
    return _luminaire.flux() * std::pow(std::max(0., R.Dot(towardsCamera)), specularExponent);

}

#endif //RAYTRACER_SHADER_H
