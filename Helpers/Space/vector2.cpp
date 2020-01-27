//
// Created by Derek.
//

#include "vector2.h"
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
