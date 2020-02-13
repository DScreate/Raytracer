//
// Created by Derek on 2/10/2020.
//

#ifndef RAYTRACER_DIFFUSERSHADER_H
#define RAYTRACER_DIFFUSERSHADER_H

#include "shader.h"

template<class T>
class DiffuseShader : public Shader<T> {
public:
    Color reflectivity;

    Color brdf(Vector3<T> _towardsLuminaire, Vector3<T> _normal, Vector3<T> _towardsCamera) const override;

    DiffuseShader<T>() : reflectivity(0, 0, 0) {};
};

template<class T>
Color DiffuseShader<T>::brdf(Vector3<T> _towardsLuminaire, Vector3<T> _normal, Vector3<T> _towardsCamera) const {
    return reflectivity;
}

#endif //RAYTRACER_DIFFUSERSHADER_H
