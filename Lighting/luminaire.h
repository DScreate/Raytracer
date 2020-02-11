//
// Created by tessa on 2/10/20.
//

#ifndef RAYTRACER_LUMINAIRE_H
#define RAYTRACER_LUMINAIRE_H
template<class T>
class Luminaire {
public:
    Vector3<T> position;

    // TODO: Look into how to relate these, this is a hack!
    Color lightColor;
    T radiantFlux;

    Luminaire<T>() : position(), lightColor(255, 255, 255) {};

    Vector3<T> towards(Vector3<T> _point);

    T irradiance(Vector3<T> _point, Vector3<T> _normal);

};

template<class T>
Vector3<T> Luminaire<T>::towards(Vector3<T> _point) {
    return position - _point;
}

template<class T>
T Luminaire<T>::irradiance(Vector3<T> _point, Vector3<T> _normal) {
    return radiantFlux * _normal.Orthonormal().Dot(_point.Orthonormal());
}

#endif //RAYTRACER_LUMINAIRE_H
