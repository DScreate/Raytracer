//
// Created by Derek.
//

#ifndef RAYTRACER_VECTOR2_H
#define RAYTRACER_VECTOR2_H

/*
 * 2D Vector for general purpose use
 * General design sourced from
 * "Fundamentals of Computer Graphics, 4th Edition" by Steve Marschner and Peter Shirley
 * pp. 9
 */
template<class T>
class Vector2 {
public:
    /*
     * Marschner and Shirley (pg. 9) suggest that Float vs. Double is largely use-case based with the trade off being
     * maintaining coherent memory access (with single precision floating point) vs. avoiding numerical problems via double
     * precision arithmetic
     */
    T x;
    T y;

    Vector2() : x(T(0)), y(T(0)) {}

    Vector2(const T& _x, const T& _y) : x(_x), y(_y) {}

    Vector2(Vector2<T>& vector2) : Vector2(vector2.x, vector2.y) {}

    Vector2& operator+=(const Vector2& that);
    Vector2& operator-=(const Vector2& that);

    Vector2& operator*=(const T& scalar);
    Vector2& operator/=(const T& scalar);

    T& Dot(Vector2& that);
};

template<class T>
Vector2<T>& Vector2<T>::operator+=(const Vector2 &that) {
    return &Vector2<T>(this.x + that.x, this.y + that.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator-=(const Vector2 &that) {
    return &Vector2<T>(this.x - that.x, this.y - that.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator*=(const T &scalar) {
    return &Vector2<T>(this.x * scalar, this.y * scalar);
}

template<class T>
Vector2<T>& Vector2<T>::operator/=(const T &scalar) {
    return &Vector2<T>(this.x / scalar, this.y / scalar);
}

template<class T>
T& Vector2<T>::Dot(Vector2 &that) {
    return &T(this.x * that.x + this.y * that.y);
}

template<class T>
Vector2<T> operator+(const Vector2<T>& Left, const Vector2<T>& Right) { return Vector2<T>(Left) += Right; }
template<class T>
Vector2<T> operator-(const Vector2<T>& Left, const Vector2<T>& Right) { return Vector2<T>(Left) -= Right; }
template<class T>
Vector2<T>& operator*(const Vector2<T>& vector2, const T& scalar) { return Vector2<T>(vector2) *= scalar; }
template<class T>
Vector2<T>& operator/(const Vector2<T>& vector2, const T& scalar) { return Vector2<T>(vector2) /= scalar; }
template<class T>
T& Dot(const Vector2<T>& Left, const Vector2<T>& Right) { return Vector2<T>(Left).Dot(Vector2<T>(Right)); }
#endif //RAYTRACER_VECTOR2_H
