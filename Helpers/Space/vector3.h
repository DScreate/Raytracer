//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H

#include <cmath>

/*tan
 * 3D Vector for general purpose use
 * General design sourced from
 * "Fundamentals of Computer Graphics, 4th Edition" by Steve Marschner and Peter Shirley
 * pp. 9
 */
template<class T>
class Vector3 {
public:
    /*
     * Marschner and Shirley (pg. 9) suggest that Float vs. Double is largely use-case based with the trade off being
     * maintaining coherent memory access (with single precision floating point) vs. avoiding numerical problems via double
     * precision arithmetic
     */
    T x;
    T y;
    T z;

    Vector3() : x(T(0)), y(T(0)), z(T(0)) {}

    Vector3(const T &_x, const T &_y, const T &_z) : x(T(_x)), y(T(_y)), z(T(_z)) {}

    Vector3(const Vector3<T> &vector3) : Vector3(vector3.x, vector3.y, vector3.z) {}

    Vector3<T> &operator+=(const Vector3<T> &that);

    Vector3<T> &operator-=(const Vector3<T> &that);

    Vector3<T> &operator*=(T scalar);

    Vector3<T> &operator/=(T scalar);

    std::ostream &operator<<(std::ostream &stream) const;

    T Dot(const Vector3<T> &that) const;

    Vector3<T> Cross(Vector3<T> &that) const;

    T Magnitude() const;

    Vector3<T> Orthonormal() const;

};


template<class T>
Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &that) {
    this->x += that.x;
    this->y += that.y;
    this->z += that.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator-=(const Vector3<T> &that) {
    this->x -= that.x;
    this->y -= that.y;
    this->z -= that.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator*=(const T scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator/=(const T scalar) {
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
    return *this;
}


template<class T>
std::ostream &Vector3<T>::operator<<(std::ostream &ostream) const {
    return ostream << "{" << this->x << ", " << this->y << ", " << this->z << "}";
}


template<class T>
T Vector3<T>::Dot(const Vector3<T> &that) const {
    return T(this->x * that.x + this->y * that.y + this->z * that.z);
}

template<class T>
Vector3<T> Vector3<T>::Cross(Vector3<T> &that) const {
    return Vector3<T>(this->y * that.z - this->z * that.y, this->z * that.x - this->x * that.z,
                      this->x * that.y - this->y * that.x);
}

template<class T>
T Vector3<T>::Magnitude() const {
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

template<class T>
Vector3<T> Vector3<T>::Orthonormal() const {
    auto inv = 1 / (this->Magnitude());
    Vector3<T> res = Vector3<T>(this->x * inv, this->y * inv, this->z * inv);
    return res;
}

template<class T>
Vector3<T> operator+(const Vector3<T> &Left, const Vector3<T> &Right) {
    Vector3<T> res = Left;
    return res += Right;
}

template<class T>
Vector3<T> operator-(const Vector3<T> &Left, const Vector3<T> &Right) {
    Vector3<T> res = Left;
    return res -= Right;
}

template<class T>
Vector3<T> operator*(const Vector3<T> &vector3, const float scalar) {
    Vector3<T> res = vector3;
    return res *= scalar;
}

template<class T>
Vector3<T> operator/(const Vector3<T> &vector3, const float scalar) {
    Vector3<T> res = vector3;
    return res /= scalar;
}

template<class T>
T Dot(const Vector3<T> &Left, const Vector3<T> &Right) {
    Vector3<T> res = Left;
    return res.Dot(Right);
}

template<class T>
Vector3<T> Cross(const Vector3<T> &Left, const Vector3<T> &Right) {
    Vector3<T> res = Left;
    return res.Cross(Right);
}

template<class T>
T Magnitude(const Vector3<T> &vector3) {
    Vector3<T> res = vector3;
    return res.Magnitude();
}

template<class T>
Vector3<T> Normalize(const Vector3<T> &vector3) {
    Vector3<T> res = vector3;
    return res.Orthonormal();
}
#endif //RAYTRACER_VECTOR3_H
