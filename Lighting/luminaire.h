//
// Created by tessa on 2/10/20.
//

#ifndef RAYTRACER_LUMINAIRE_H
#define RAYTRACER_LUMINAIRE_H

#include <cmath>
#include "../constants.h"

template<class T>
class Luminaire {
public:
    Vector3<T> position;

    // TODO: Look into how to relate these, this is a hack!
    Color lightColor;
    T intensity = 35.0f;

    Luminaire<T>() : position(), lightColor(1, 1, 1) {};

    Vector3<T> towardsLum(Vector3<T> _point) const;

    Vector3<T> halfway(Vector3<T> &_towardsCamera, Vector3<T> &_point) const;

    virtual Color irradiance(Vector3<T> _point, Vector3<T> _normal);

    virtual bool isBetween(const Vector3<T> &_pointA, const Vector3<T> &_pointB, const Ray<T> &_shadowRay) const;

    virtual Color flux();

};

template<class T>
Vector3<T> Luminaire<T>::towardsLum(Vector3<T> _point) const {
    return position - _point;
}

template<class T>
Color Luminaire<T>::irradiance(Vector3<T> _point, Vector3<T> _normal) {
    Color val = flux() * std::max(T(0), _normal.Dot(towardsLum(_point).Orthonormal()));

    return val;
}

template<class T>
bool Luminaire<T>::isBetween(const Vector3<T> &_pointA, const Vector3<T> &_pointB, const Ray<T> &_shadowRay) const {
    Vector3<T> diffBA = _pointB - _pointA;
    Vector3<T> diffPA = position - _pointA;
    Vector3<T> cross = diffBA.Cross(diffPA);
    if (abs(cross.Magnitude()) > EPSILON) {
        return false;
    }

    return !(diffBA.Magnitude() - diffPA.Magnitude() < EPSILON);

}

template<class T>
Color Luminaire<T>::flux() {
    return lightColor * intensity;
}

template<class T>
Vector3<T> Luminaire<T>::halfway(Vector3<T> &_towardsCamera, Vector3<T> &_point) const {
    Vector3<T> res = towardsLum(_point) + _towardsCamera;

    return (res / res.Magnitude());
}


#endif //RAYTRACER_LUMINAIRE_H
