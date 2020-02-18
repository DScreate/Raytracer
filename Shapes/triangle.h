//
// Created by tessa on 2/17/20.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "../target.h"

template<class T>
class Triangle : public Target {
private:
    T dToOrigin;
    Vector3<T> vertex0;
    Vector3<T> vertex1;
    Vector3<T> vertex2;
public:

    const Vector3<T> &getVertex0() const;

    void setVertex0(const Vector3<T> &_vertex0);

    const Vector3<T> &getVertex1() const;

    void setVertex1(const Vector3<T> &_vertex1);

    const Vector3<T> &getVertex2() const;

    void setVertex2(const Vector3<T> &_vertex2);


public:


    Triangle() : vertex0(), vertex1(), vertex2() {
        init();
    };

    Triangle(Vector3<T> _vertex0, Vector3<T> _vertex1, Vector3<T> _vertex2) : vertex0(_vertex0), vertex1(_vertex1),
                                                                              vertex2(_vertex2) {
        init();
    };

    void init() const;

    Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const override;

    Vector3<T> getNormal() const;

    Vector3<T> getNormal(const Vector3<T> &point) const override;
};

template<class T>
Intersection<T> Triangle<T>::firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const {

}

template<class T>
Vector3<T> Triangle<T>::getNormal(const Vector3<T> &point) const {
}

template<class T>
Vector3<T> Triangle<T>::getNormal() const {
    return (vertex1 - vertex0).Cross(vertex2 - vertex0);
}

template<class T>
void Triangle<T>::init() const {
    dToOrigin = (getNormal() * -1).Dot(vertex0);
}

template<class T>
const Vector3<T> &Triangle<T>::getVertex0() const {
    return vertex0;
}

template<class T>
void Triangle<T>::setVertex0(const Vector3<T> &_vertex0) {
    Triangle::vertex0 = _vertex0;
    init();
}

template<class T>
const Vector3<T> &Triangle<T>::getVertex1() const {
    return vertex1;
}

template<class T>
void Triangle<T>::setVertex1(const Vector3<T> &_vertex1) {
    Triangle::vertex1 = _vertex1;
    init();
}

template<class T>
const Vector3<T> &Triangle<T>::getVertex2() const {
    return vertex2;
}

template<class T>
void Triangle<T>::setVertex2(const Vector3<T> &_vertex2) {
    Triangle::vertex2 = _vertex2;
    init();
}

#endif //RAYTRACER_TRIANGLE_H