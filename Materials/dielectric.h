#ifndef RAYTRACER_DIELECTRIC_H
#define RAYTRACER_DIELECTRIC_H

#include "shader.h"

template<class T>
class Dielectric : public Shader<T> {
public:
    Color reflectivity;

    Color brdf(Vector3<T> &_towardsLuminaire, Vector3<T> &_normal, Vector3<T> &_towardsCamera) const;

    T refractiveIndex = T(1);

    Dielectric<T>() : reflectivity(0, 0, 0) {};

    T fresnel(const Vector3<T> &_direction, const Vector3<T> &_normal, const Vector3<T> &_halfway, const T &_eta) const;

    Color indirectRadiance(const Intersection<T> &_intersection, const Ray<T> &_incidentRay,
                           const Scene<T> &_scene) const override;
};

template<class T>
Color Dielectric<T>::indirectRadiance(const Intersection<T> &_intersection, const Ray<T> &_incidentRay,
                                      const Scene<T> &_scene) const {

    Vector3<T> towardsCamera = _incidentRay.direction.Orthonormal() * -1;
    Vector3<T> normal = _intersection.getNormal().Orthonormal();
    Ray<T> reflectedRay = Ray<T>(_intersection.point, towardsCamera.Reflect(normal), 1, 0, _scene.maxRayDistance,
                                 _incidentRay.refractiveIndex,
                                 _incidentRay.depth + 1);
    Color radiance = _scene.traceRay(reflectedRay, EPSILON);
    Vector3<T> transmittedDirection = towardsCamera.Refract(normal, _scene.ambientRefractiveIndex, refractiveIndex);
    if (transmittedDirection.Magnitude() > EPSILON) {
        Vector3<T> adjustment = normal * EPSILON;
        Vector3<T> adjustedPoint = _intersection.point - adjustment;
        Ray<T> refractedRay = Ray<T>(_intersection.point, transmittedDirection, 1, 0., _scene.maxRayDistance,
                                     refractiveIndex, _incidentRay.depth + 1);
        Vector3<T> towardsLum = (_incidentRay.direction * -1);
        Vector3<T> halfway = (towardsLum + towardsCamera) / (towardsLum + towardsCamera).Magnitude();
        T f = fresnel(towardsCamera, normal, halfway, _scene.ambientRefractiveIndex / refractiveIndex);
        if (f < (T(1) + EPSILON)) {
            radiance = radiance * f + _scene.traceRay(refractedRay, EPSILON) * (T(1) - f);
        }
    }
    return radiance;

}

template<class T>
Color Dielectric<T>::brdf(Vector3<T> &_towardsLuminaire, Vector3<T> &_normal, Vector3<T> &_towardsCamera) const {
    return reflectivity;
}

template<class T>
T Dielectric<T>::fresnel(const Vector3<T> &_direction, const Vector3<T> &_normal, const Vector3<T> &_halfway,
                         const T &_etaL) const {

    T etaLambda = refractiveIndex / _etaL;
    T lDotH = _direction.Dot(_halfway);
    T g = sqrt(pow(etaLambda, 2) - 1 + (pow(lDotH, 2)));

    T gMinusLDotH = (g - lDotH);
    T gPlusLDotH = (g + lDotH);

    T fLambda = 0.5 * pow(gMinusLDotH, 2) / pow(gPlusLDotH, 2) *
                (pow(lDotH * gPlusLDotH - 1, 2) / pow(lDotH * gMinusLDotH + 1, 2) + 1);


    return fLambda;
}

#endif //RAYTRACER_DIELECTRIC_H
