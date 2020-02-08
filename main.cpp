#include <iostream>
#include "Helpers/image.h"
#include "scene.h"
#include " Shapes/sphere.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    const int width = 256;
    const int height = 256;
    const int wMult = 3;
    const int hMult = 3;
    const int derivedWidth = width * wMult;
    const int derivedHeight = height * hMult;

    Image<float> image(derivedWidth, derivedHeight);

    Scene<float> mainScene{};

    Sphere<float> testSphere = Sphere<float>();
    mainScene.targets.push_back(std::make_unique<Sphere<float>>(testSphere));

    Ray<float>& ray();
    Radiance<float>& radiance();

    for(int u = 0; u < derivedWidth; u++) {
        for(int v = 0; v < derivedHeight; v++) {
            //
            // for each pixel
            // compute viewing ray
            // intersect ray with scene
            // compute illumination at visible point
            // put result into image
            //
            image.setPixel(u, v, Color(u % 256, v % 256, 0));
        }
    }
    //image.initDummyData();
    image.output();
    return 0;
}