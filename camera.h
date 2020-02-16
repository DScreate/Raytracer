//
// Created by Derek on 1/25/2020.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include <cmath>

#include "Helpers/image.h"
#include "scene.h"
#include "radiance.h"
#include "Helpers/random.h"

#define PI 3.14159265
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
    int antiAliasFactor = 1;
    bool antiAlias = false;
    int dofSamples = 1;
    bool dof = false;
    T focalLength = 1.0f;
    T lensSize = 2.0f;
    float fov = 47.0f;

    Camera() : position(Vector3<T>()), lookAt(Vector3<T>(0.0, 0.0, -1.0)),
               viewUp(Vector3<T>(0.0, 1.0, 0.0)), fov(60.0f), antiAlias(false), antiAliasFactor(1) {}

    Camera(const Vector3<T> &_position, const Vector3<T> &_lookAt, const Vector3<T> &_viewUP)
            :
            position(_position), lookAt(_lookAt), viewUp(_viewUP) {}

    /*
     * Converts a Scene and a Camera into an image
     */
    Image<T> renderImage(Scene<T> *scene, const int &width, const int &height);

    //Color renderPixel(const Scene<T> &scene, const int &width, const int &height, const int &iu, const int &iv) const;
    Vector3<T> getCameraCoordinatePoint(const float &i, const float &j) const;

    void initBasis();

    void setImage(const Image<T> &_image);

    /*
     * u = (i + 0.5)/nx
     * v = (j + 0.5)/ny
     */
    Ray<T> generateRay(const int &width, const int &height, const T &u, const T &v) const;

    vector<Ray<T>> generateLensRays(const int &width, const int &height, const T &u, const T &v) const;

    Color renderPixel(Scene<T> *scene, const int &width, const int &height, const T &iu, const T &iv);

    vector<Vector3<T>> lensPoints() const;

    Vector3<T> opposingFocalPoint(const Vector3<T> &_position) const;

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
    //Vector3<T> oPrime = getCameraCoordinatePoint(u, v);
    //Vector3<T> dPrime = oPrime * -1;
    Vector3<T> _d = x * (u - ((width - 1) / 2)) + y * (v - ((height - 1) / 2)) - (z * d);
    //Vector3<T> d = (x * (-dPrime.x)) - (y * dPrime.y) - (z * dPrime.z);
    return Ray<T>(position, _d.Orthonormal(), 1, 0, 1000, 1, 0);
}

template<class T>
Image<T> Camera<T>::renderImage(Scene<T> *scene, const int &width, const int &height) {
    image = Image<T>(width, height);
    initBasis();
    for (int iu = 0; iu < width; iu++) {
        for (int iv = 0; iv < height; iv++) {
            int column = iu;
            int row = height - 1 - iv;
            Color color = Color(0, 0, 0);
            if (antiAlias) {
                for (int i = 0; i < antiAliasFactor; i++) {
                    color += renderPixel(scene, width, height, iu + makeRandom<T>(), iv + makeRandom<T>()) /
                             antiAliasFactor;
                }
            } else {
                color = renderPixel(scene, width, height, iu, iv);
            }
            image.setPixel(column, row, color);
        }
    }

    return image;
}

template<class T>
void Camera<T>::initBasis() {
    Vector3<T> Z = lookAt - position;
    this->z = Z.Orthonormal();
    this->z *= -1;
    Vector3<T> X = viewUp.Cross(this->z);
    this->x = X.Orthonormal();
    y = z.Cross(x);
    this->d = image.height / (2 * tan((fov / 2) * PI / 180.0));
}

template<class T>
void Camera<T>::setImage(const Image<T> &_image) {
    this->image = _image;
}

template<class T>
Vector3<T> Camera<T>::getCameraCoordinatePoint(const float &i, const float &j) const {
    float _x = ((image.width - 1) / 2) - i;
    float _y = ((image.height - 1) / 2) - j;
    return Vector3<T>(_x, _y, this->d);
}

template<class T>
Color Camera<T>::renderPixel(Scene<T> *scene, const int &width, const int &height, const T &iu, const T &iv) {

    if (dof) {
        Color mix = scene->backgroundRadiance;
        vector<Ray<T>> rays = generateLensRays(width, height, iu + 0.5, iv + 0.5);
        for (Ray<T> ray : rays) {
            mix += scene->traceRay(ray, 0);
        }

        return mix;
    } else {
        Ray<T> ray = generateRay(width, height, iu + 0.5, iv + 0.5);
        return scene->traceRay(ray, 0);
    }
}

template<class T>
vector<Ray<T>> Camera<T>::generateLensRays(const int &width, const int &height, const T &u, const T &v) const {
    //Vector3<T> oPrime = getCameraCoordinatePoint(u, v);
    //Vector3<T> dPrime = oPrime * -1;
    Vector3<T> _d = x * (u - ((width - 1) / 2)) + y * (v - ((height - 1) / 2)) - (z * d);
    //Vector3<T> d = (x * (-dPrime.x)) - (y * dPrime.y) - (z * dPrime.z);
    Vector3<T> pixelRayOrigin = Vector3<T>(u, v, d);
    auto C = opposingFocalPoint(position);
    vector<Ray<T>> rays;
    for (auto lensPoint : lensPoints()) {
        Vector3<T> lensRayDirection = C - lensPoint;
        auto cameraRay = Ray<T>(lensPoint, lensRayDirection.Orthonormal(), 1, 0, 1000, 1, 0);
        rays.push_back(cameraRay);
    }

    return rays;
}


// TODO: Change the range of the loop
template<class T>
vector<Vector3<T>> Camera<T>::lensPoints() const {
    vector<Vector3<T>> points;
    for (int i = 0; i < dofSamples; i++) {
        points.push_back(Vector3<T>(makeRandom<T>() * lensSize, makeRandom<T>() * lensSize, focalLength));
    }

    return points;
}

// TODO: Generate actual calculation for this
template<class T>
Vector3<T> Camera<T>::opposingFocalPoint(const Vector3<T> &_position) const {
    // 1/P + 1/Vp = 1/F
    // Vp = abs(o dot z), P = abs(C dot z)
    // P = - FVp / (F - Vp)
    // C = |C|C^
    // |C dot z| = - F * |o dot z| / (F - |o dot z|)
    auto P = -(focalLength * _position.z) / (focalLength - _position.z);
    return Vector3<T>(_position.x + makeRandom<T>(), _position.y + makeRandom<T>(), _position.z + makeRandom<T>());
}

#endif //RAYTRACER_CAMERA_H
