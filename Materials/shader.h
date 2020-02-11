//
// Created by tessa on 2/10/20.
//

#ifndef RAYTRACER_SHADER_H
#define RAYTRACER_SHADER_H

#include "material.h"
#include "../Lighting/luminaire.h"

template<class T>
class Shader : public Material<T> {
    Color directRadiance(Intersection<T> _intersection, Vector3<T> _towardsCamera, Luminaire<T> _luminaire);
};

template<class T>
Color Shader<T>::directRadiance(Intersection<T> _intersection, Vector3<T> _towardsCamera, Luminaire<T> _luminaire) {

    Vector3<T> normal = Vector3<T>();//.target->getNormal()
    Vector3<T> towardsLuminaire = _luminaire.towards(_intersection.p);
}

#endif //RAYTRACER_SHADER_H
