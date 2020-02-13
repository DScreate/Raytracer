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

    Vector3<T> towardsLum(Vector3<T> _point);

    Color irradiance(Vector3<T> _point, Vector3<T> _normal);

    bool isBetween(Vector3<T> _pointA, Vector3<T> _pointC);

    Color flux() {
        return lightColor * intensity;
    }

};

template<class T>
Vector3<T> Luminaire<T>::towardsLum(Vector3<T> _point) {
    return position - _point;
}

template<class T>
Color Luminaire<T>::irradiance(Vector3<T> _point, Vector3<T> _normal) {
    Color val = flux() * std::max(T(0), _normal.Dot(towardsLum(_point)));

    return val;
}

template<class T>
bool Luminaire<T>::isBetween(Vector3<T> _pointA, Vector3<T> _pointC) {
    Vector3<T> cross = (position - _pointA).Cross(_pointC - _pointA);
    if (fabs(cross.Magnitude()) > EPSILON) {
        return false;
    }

    T dot = (position - _pointA).Dot(_pointC - _pointA);
    if (dot < 0) {
        return false;
    }

    T dist = (position - _pointA).Magnitude();
    if (dot > dist) {
        return false;
    }

    return true;
}


#endif //RAYTRACER_LUMINAIRE_H
