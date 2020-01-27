//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H


/*
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

    Vector3(const T& _x, const T& _y, const T& _z) : x(_x), y(_y), z(_z) {}

    Vector3& operator+=(const Vector3& that);
    Vector3& operator-=(const Vector3& that);

    Vector3& operator*=(const T& scalar);
    Vector3& operator/=(const T& scalar);

    T& Dot(Vector3& that);
    Vector3& Cross(Vector3& that);

};

template<class T>
Vector3<T> operator+(const Vector3<T>& Left, const Vector3<T>& Right) { return Vector3<T>(Left) += Right; }
template<class T>
Vector3<T> operator-(const Vector3<T>& Left, const Vector3<T>& Right) { return Vector3<T>(Left) -= Right; }
template<class T>
Vector3<T>& operator*(const Vector3<T>& vector3, const T& scalar) { return Vector3<T>(vector3) *= scalar; }
template<class T>
Vector3<T>& operator/(const Vector3<T>& vector3, const T& scalar) { return Vector3<T>(vector3) /= scalar; }
template<class T>
T& Dot(const Vector3<T>& Left, const Vector3<T>& Right) { return Vector3<T>(Left).Dot(Vector3<T>(Right)); }
template<class T>
Vector3<T>& Cross(const Vector3<T>& Left, const Vector3<T>& Right) { return Vector3<T>(Left).Cross(Vector3<T>(Right)); }


#endif //RAYTRACER_VECTOR3_H
