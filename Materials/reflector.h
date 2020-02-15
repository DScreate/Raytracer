//
// Created by Derek on 2/12/2020.
//

#ifndef RAYTRACER_REFLECTOR_H
#define RAYTRACER_REFLECTOR_H

#include "shader.h"

template<class T>
class Reflector : public Shader<T> {
public:
    Color reflectivity;

    T reflectivityLoss = T(.80);

    Color brdf(Vector3<T> _towardsLuminaire, Vector3<T> _normal, Vector3<T> _towardsCamera) const;

    Reflector<T>() : reflectivity(0, 0, 0) {};

    Color indirectRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Scene<T> _scene) const override;

};

template<class T>
Color Reflector<T>::brdf(Vector3<T> _towardsLuminaire, Vector3<T> _normal, Vector3<T> _towardsCamera) const {
    return reflectivity * reflectivityLoss;
}

template<class T>
Color Reflector<T>::indirectRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Scene<T> _scene) const {
    Vector3<T> towardsCamera = _incidentRay.direction.Orthonormal() * -1;
    Vector3<T> normal = _intersection.getNormal();
    Ray<T> reflectedRay = Ray<T>(_intersection.point, towardsCamera.Reflect(normal), _incidentRay.refractiveIndex,
                                 _incidentRay.depth + 1);
    return reflectivity * _scene.traceRay(reflectedRay, EPSILON);
}

/*
template<class T>
Color
Reflector<T>::illuminate(const Intersection<T> &_intersection, const Ray<T> &_incidentRay,
                         const Scene<T> &_scene) const {
    Color color = Color();

    color += indirectRadiance(_intersection, _incidentRay, _scene);
    Vector3<T> towardsCamera = _incidentRay.direction * -1;
    Vector3<T> point = _intersection.point;
    Vector3<T> normal = _intersection.getNormal();
    Vector3<T> towardsLuminaire;
    for (Luminaire<T> *luminaire : _scene.luminaires) {
        towardsLuminaire = luminaire->towardsLum(point).Orthonormal();
        auto temp = normal.Dot(towardsLuminaire);
        if (normal.Dot(towardsLuminaire) > 0) { // above horizon
            color += directRadiance(_intersection, _incidentRay, *luminaire);
        }
    }
    return color;
}
*/

#endif //RAYTRACER_REFLECTOR_H
