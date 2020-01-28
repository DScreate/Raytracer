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
public:
    /*
     * Converts a Scene and a Camera into an image
     */
    Image<T> renderImage(Camera<T> camera, Scene<T> scene, int width, int height);
    Radiance<T> renderPixel(Camera<T> camera, Scene<T> scene, int width, int height);

    /*
     * u = (i + 0.5)/nx
     * v = (j + 0.5)/ny
     */
    Ray<T> generateRay(T u, T v);
};


#endif //RAYTRACER_CAMERA_H
