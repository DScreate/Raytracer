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
    Vector3<T> u;
    Vector3<T> v;
    Vector3<T> n;

public:
    Vector3<T> position;

    Camera() : position(Vector3<T>()) {};
    Camera(Vector3<T> &_position) : position(_position) {};
    /*
     * Converts a Scene and a Camera into an image
     */
    Image<T> renderImage(const Camera<T> &camera, const Scene<T> &scene, const int &width, const int &height);
    RGB<T> renderPixel(const Camera<T> &camera, const Scene<T> &scene, const int &width, const int &height);

    /*
     * u = (i + 0.5)/nx
     * v = (j + 0.5)/ny
     */
    Ray<T> generateRay(const T &u, const T &v);
};

// TODO: Convert this to Radiance?
template<class T>
RGB<T> Camera<T>::renderPixel(const Camera<T> &camera, const Scene<T> &scene, const int &width, const int &height) {
    // l and r are he positions of the left and right edges of the image, as measured from e along the u direction
    // b and t are the positions of the bottom and top edges of the image as measured from e along the v direction
    // many systems assume that l = -r and b = -t so that a width and a height suffice
    T l = -r;
    T b = -t;
    T u = l + (r-l)(pixel_i+0. 5)/image.width;
    T v = b + (t-b)(pixel_j+0.5)/image.height;
    Ray<T> camera.viewingRay(width, height, iu + 0.5, iv + 0.5);
    return scene.traceRay(ray, 0);
}

template<class T>
Ray<T> Camera<T>::generateRay(const T &u, const T &v) {
    return Ray<T>();
}

template<class T>
Image<T> Camera<T>::renderImage(const Camera<T> &camera, const Scene<T> &scene, const int &width, const int &height) {
    Image<T> image = Image(width, height);
    for (int iu = 0; iu < width; iu++) {
        for (int iv = 0; iv < height; iv++) {
            int column = iu;
            int row = height - 1 - iv;
            image.setPixel(column, row, camera.renderPixel(scene, width, height, iu, iv));
        }
    }

    return image;
}


#endif //RAYTRACER_CAMERA_H
