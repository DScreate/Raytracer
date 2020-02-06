#include <iostream>
#include "Helpers/image.h"
#include "scene.h"
#include " Shapes/sphere.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    const int width = 256;
    const int height = 256;
    const int wMult = 1;
    const int hMult = 1;

    Image<float> image(width * wMult, height * hMult);

    Scene<float> mainScene{};

    Sphere<float> testSphere = Sphere<float>();

    mainScene.addTarget(testSphere);
    /*
    Ray<float>& ray();
    Radiance<float>& radiance();
*/
    for(int u = 0; u < width; u++) {
        for(int v = 0; v < height; v++) {
            //
            // for each pixel
            // compute viewing ray
            // intersect ray with scene
            // compute illumination at visible point
            // put result into image
            //
            image.setPixel(u, v, Color(u, v, 0));
        }
    }
    image.output();

    return 0;
}