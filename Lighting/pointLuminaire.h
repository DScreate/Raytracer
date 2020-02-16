//
// Created by tessa on 2/13/20.
//

#ifndef RAYTRACER_POINTLUMINAIRE_H
#define RAYTRACER_POINTLUMINAIRE_H

#include "luminaire.h"
#include "../Helpers/Space/vector3.h"
#include "../Helpers/rgb.h"
#include "../camera.h"

template<class T>
class PointLuminaire : public Luminaire<T> {

    PointLuminaire<T>() = default;

    Color irradiance(Vector3<T> _point);
};

template<class T>
Color PointLuminaire<T>::irradiance(Vector3<T> _point) {
    return Luminaire<T>::flux() / (4 * PI * pow((_point - this->position).Magnitude(), 2));
}

#endif //RAYTRACER_POINTLUMINAIRE_H
