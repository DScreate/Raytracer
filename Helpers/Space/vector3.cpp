//
// Created by Derek
//

#include "vector3.h"

template<class T>
Vector3<T>& Vector3<T>::operator+=(const Vector3 &that) {
    return &Vector3<T>(this->x + that.x, this->z + that.y, this->z + that.z);
}

template<class T>
Vector3<T>& Vector3<T>::operator-=(const Vector3 &that) {
    return &Vector3<T>(this->x - that.x, this->y - that.y, this->z - that.z);
}

template<class T>
Vector3<T>& Vector3<T>::operator*=(const T &scalar) {
    return &Vector3<T>(this->x * scalar, this->y * scalar, this->z * scalar);
}

template<class T>
Vector3<T>& Vector3<T>::operator/=(const T &scalar) {
    return &Vector3<T>(this->x / scalar, this->y / scalar, this->z / scalar);
}

template<class T>
T& Vector3<T>::Dot(Vector3 &that) {
    return &T(this->x * that.x + this->y * that.y, this->z * that.z);
}

template<class T>
Vector3<T>& Vector3<T>::Cross(Vector3 &that) {
    return Vector3<T>( this->y * that.z - this->z * that.y, this->z * that.x - this->x * that.z, this->x * that.y - this->y * that.x);
}
