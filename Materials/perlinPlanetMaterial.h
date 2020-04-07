//
// Created by tessa on 3/9/20.
//

#ifndef RAYTRACER_PERLINPLANETMATERIAL_H
#define RAYTRACER_PERLINPLANETMATERIAL_H


#include "./shader.h"
#include "../perlin_lewis/perlin.h"
#include "../Shapes/planetoid.h"

template<class T>
class PerlinPlanetMaterial : public Shader<T> {
public:
    Color reflectivity;
    Planetoid<T> *planetoid;
    Image<T> samplingImage;

    Color brdf(Vector3<T> &_towardsLuminaire, Vector3<T> &_normal, Vector3<T> &_towardsCamera) const override;

    PerlinPlanetMaterial<T>(Planetoid<T> *_planetoid) : reflectivity(0, 0, 0) {
        planetoid = _planetoid;
        initSamplingImage();
    };

    Color directRadiance(Intersection<T> _intersection, Ray<T> _incidentRay, Luminaire<T> _luminaire) const;

    Color indirectRadiance(Intersection<T> &_intersection, Ray<T> &_incidentRay, Scene<T> &_scene) const;

    void initSamplingImage();
};

template<class T>
Color
PerlinPlanetMaterial<T>::brdf(Vector3<T> &_towardsLuminaire, Vector3<T> &_normal, Vector3<T> &_towardsCamera) const {
    return Color();
}

template<class T>
Color PerlinPlanetMaterial<T>::indirectRadiance(Intersection<T> &_intersection, Ray<T> &_incidentRay,
                                                Scene<T> &_scene) const {
    return Color();
}

template<class T>
void PerlinPlanetMaterial<T>::initSamplingImage() {
    samplingImage = samplingImage.getImage("terrain sample.ppm");
}

template<class T>
Color PerlinPlanetMaterial<T>::directRadiance(Intersection<T> _intersection, Ray<T> _incidentRay,
                                              Luminaire<T> _luminaire) const {

    double values[3] = {_intersection.point.x, _intersection.point.y, _intersection.point.z};
    double noiseValue = noise(values, 3);
    double latitude = this->planetoid->getLatitude(_intersection.point);

    //std::cout << latitude << std::endl;

    // 1 = imageWidth
    // -1 = 0
    // 0 = imageWidth / 2

    T x = noiseValue;
    //double otherValues[3] = {_intersection.point.x, _intersection.point.y, _intersection.point.z};
    //double otherNoise = noise(otherValues, 3);
    //x *= abs(otherNoise);
    T y = abs(latitude) / 90.;

    int imageX = int(samplingImage.width * x);
    int imageY = int(samplingImage.height * y);

    return samplingImage.getPixel(imageX, imageY);
}

#endif //RAYTRACER_PERLINPLANETMATERIAL_H
