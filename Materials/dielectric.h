//
// Created by Derek on 2/13/2020.
//

#ifndef RAYTRACER_DIELECTRIC_H
#define RAYTRACER_DIELECTRIC_H

#include "shader.h"

template<class T>
class Dielectric : public Shader<T> {
public:
    //Color brdf(Vector3<T> _towardsLuminaire, Vector3<T> _normal, Vector3<T> _towardsCamera) const;

    T refractiveIndex = T(1);

    Dielectric<T>() : reflectivity(0, 0, 0) {};

    //Color indirectRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Scene<T> _scene) const override;
};

template<class T>
Color Dielectric<T>::indirectRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Scene<T> _scene) const {
    /*
    Vector3<T> towardsCamera = _incidentRay.direction.Orthonormal() * -1;
    Vector3<T> normal = _intersection.getNormal();
    T incidentRefractiveIndex;
    T transmittedRefractiveIndex;
    if (_incidentRay.refractiveIndex - scene.ambientRefractiveIndex < EPSILON) {
        incidentRefractiveIndex = _incidentRay.refractiveIndex;
        transmittedRefractiveIndex = refractiveIndex;
    } else {
        normal *= -1;
        incidentRefractiveIndex = refractiveIndex;
        transmittedRefractiveIndex = scene.ambientRefractiveIndex;
    }
    Ray<T> reflectedRay = Ray<T>(_intersection.point, towardsCamera.Reflect(normal), _incidentRay.refractiveIndex,
                                 _incidentRay.depth + 1);
    Color radiance = _scene.traceRay(reflectedRay, EPSILON);
    T eta = _incidentRay.refractiveIndex / refractiveIndex;
    Vector3<T> transmittedDirection = towardsCamera.refract(normal, eta);
    if (transmittedDirection.Magnitude() < EPSILON) {
        Ray<T> refractedRay = Ray(_intersection.point, transmittedDirection, refractiveIndex, _incidentRay.depth+1);
        T f = fresnel(towardsCamera, normal, eta);
        if (f < 1.0f) {
            radiance = f * radiance + (T(1) - f) * _scene.traceRay(refractedRay, EPSILON);
        }
    }
    return radiance;
     */
}

#endif //RAYTRACER_DIELECTRIC_H
