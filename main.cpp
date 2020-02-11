#include <iostream>
#include "Helpers/image.h"
#include "scene.h"
#include "Shapes/sphere.h"
#include "camera.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    const int width = 256;
    const int height = 256;
    const int wMult = 8;
    const int hMult = 4;
    const int derivedWidth = width * wMult;
    const int derivedHeight = height * hMult;

    //Image<float> image(derivedWidth, derivedHeight);

    Scene<float> mainScene{};

    Sphere<float> testSphere1 = Sphere<float>();
    testSphere1.radius = 5;
    testSphere1.center = Vector3<float>(0, 0, 0);
    mainScene.targets.push_back(&testSphere1);

    /*
    Sphere<float> testSphere2 = Sphere<float>();
    testSphere2.radius = 3;
    testSphere2.center = Vector3<float>(0, 0, -10);
    mainScene.targets.push_back(&testSphere2);
     */

    Vector3<float> camPosition = Vector3<float>(0, 0, 100);
    Vector3<float> camLookAt = Vector3<float>(0, 0, 0);
    Vector3<float> camViewUp = Vector3<float>(0, 1, 0);

    Camera<float> mainCam = Camera<float>(camPosition, camLookAt, camViewUp, 60);

    // put result into image
    Image<float> outputImage = mainCam.renderImage(mainScene, derivedWidth, derivedHeight);

    //image.initDummyData();
    outputImage.output();
    return 0;
}