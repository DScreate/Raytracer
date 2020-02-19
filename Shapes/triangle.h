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
public:
    T getDToOrigin() const;

    void setDToOrigin(T dToOrigin);

private:
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

    void init();

    Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const override;

    Vector3<T> getNormal() const;

    Vector3<T> getNormal(const Vector3<T> &point) const override;
};

template<class T>
Intersection<T> Triangle<T>::firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const {
    Vector3<T> normal = getNormal().Orthonormal();

    T D = normal.Dot(getVertex0());

    Intersection<T> res;

    res.tMin = -(normal.Dot(ray.origin) + D) / normal.Dot(ray.direction);


    if (res.tMin < 0) {
        return res;
    }


    if (res.tMin < tMin || res.tMin > tMax) {
        return res;
    }

    Vector3<T> adjustment = ray.direction.Orthonormal() * EPSILON;
    res.point = ray.origin - adjustment + ray.direction * res.tMin;

    Vector3<T> edge01 = getVertex1() - getVertex0();
    Vector3<T> edge21 = getVertex2() - getVertex1();
    Vector3<T> edge02 = getVertex0() - getVertex2();

    Vector3<T> c0 = res.point - getVertex0();
    Vector3<T> c1 = res.point - getVertex1();
    Vector3<T> c2 = res.point - getVertex2();

    if (normal.Dot(edge01.Cross(c0)) > 0 && normal.Dot(edge21.Cross(c1)) > 0 && normal.Dot(edge02.Cross(c2)) > 0) {
        res.target = this;
        res.hit = true;
    }

    return res;
}

template<class T>
Vector3<T> Triangle<T>::getNormal(const Vector3<T> &point) const {
    return getNormal();
}

template<class T>
Vector3<T> Triangle<T>::getNormal() const {
    Vector3<T> left = vertex1 - vertex0;
    Vector3<T> right = vertex2 - vertex0;
    return left.Cross(right);
}

template<class T>
void Triangle<T>::init() {
    setDToOrigin((getNormal() * -1).Dot(vertex0));
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

template<class T>
T Triangle<T>::getDToOrigin() const {
    return dToOrigin;
}

template<class T>
void Triangle<T>::setDToOrigin(T _dToOrigin) {
    Triangle::dToOrigin = _dToOrigin;
}

#endif //RAYTRACER_TRIANGLE_H