//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "Helpers/image.h"
#include "scene.h"
#include "radiance.h"

template<class T>
class Camera {
private:
    Vector3<T> x; // "u"
    Vector3<T> y; // "v"
    Vector3<T> z; // "n"
    T d; // distance in "pixels" from origin to the image plane
    Image<T> image;

public:
    Vector3<T> position;
    Vector3<T> lookAt;
    Vector3<T> viewUp;
    float fov;

    Camera() : position(Vector3<T>()), lookAt(Vector3<T>(0.0, 0.0, -1.0)),
               viewUp(Vector3<T>(0.0, 1.0, 0.0)), fov(60.0f), image() { initBasis(); }

    Camera(const Vector3<T> &_position, const Vector3<T> &_lookAt, const Vector3<T> &_viewUP, const float &_fov,
           Image<T> &_image) :
            position(_position), lookAt(_lookAt), viewUp(_viewUP), fov(_fov), image(_image) { initBasis(); }

    /*
     * Converts a Scene and a Camera into an image
     */
    Image<T> renderImage(const Scene<T> &scene, const int &width, const int &height);

    //Color renderPixel(const Scene<T> &scene, const int &width, const int &height, const int &iu, const int &iv) const;
    Vector3<T> getCameraCoordinatePoint(const float &i, const float &j) const;

    void initBasis();

    void setImage(const Image<T> &_image);

    /*
     * u = (i + 0.5)/nx
     * v = (j + 0.5)/ny
     */
    Ray<T> generateRay(const int &width, const int &height, const T &u, const T &v) const;

    Color renderPixel(Scene<T> scene, const int &width, const int &height, const int &iu, const int &iv) {
        Ray<T> ray = generateRay(width, height, iu + 0.5, iv + 0.5);
        return scene.traceRay(ray, 0);
    }
};

/*
// TODO: Convert this to Radiance?
template<class T>
Color Camera<T>::renderPixel(const Scene<T> &scene, const int &width, const int &height, const int &iu, const int &iv) const {
    Ray<T> ray = generateRay(width, height, iu + 0.5, iv + 0.5);
    return scene.traceRay(ray, 0);
}
 */

template<class T>
Ray<T> Camera<T>::generateRay(const int &width, const int &height, const T &u, const T &v) const {
    Vector3<T> oPrime = getCameraCoordinatePoint(u, v);
    Vector3<T> dPrime = oPrime * -1;
    //Vector3<T> d = (u - ((width - 1) / 2))*x + (v - ((h-1)/2))*y - (d * z);
    Vector3<T> d = (x * (-dPrime.x)) - (y * dPrime.y) - (z * dPrime.z);
    return Ray<T>(position, d.Orthonormal(), 1);
}

template<class T>
Image<T> Camera<T>::renderImage(const Scene<T> &scene, const int &width, const int &height) {
    Image<T> image = Image<T>(width, height);
    for (int iu = 0; iu < width; iu++) {
        for (int iv = 0; iv < height; iv++) {
            int column = iu;
            int row = height - 1 - iv;
            Color color = renderPixel(scene, width, height, iu, iv);
            image.setPixel(column, row, color);
        }
    }

    return image;
}

template<class T>
void Camera<T>::initBasis() {
    Vector3<T> Z = position - lookAt;
    this->z = Z.Orthonormal();
    this->z *= -1;
    Vector3<T> X = viewUp.Cross(this->z);
    this->x = X.Orthonormal();
    y = z.Cross(x);
    this->d = image.height / (2 * tan(fov / 2));
}

template<class T>
void Camera<T>::setImage(const Image<T> &_image) {
    this->image = _image;
}

template<class T>
Vector3<T> Camera<T>::getCameraCoordinatePoint(const float &i, const float &j) const {
    float x = ((image.width - 1) / 2) - i;
    float y = ((image.height - 1) / 2) - j;
    return Vector3<T>(x, y, this->d);
}


#endif //RAYTRACER_CAMERA_H
