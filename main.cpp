#include <iostream>
#include "Helpers/image.h"
#include "scene.h"
#include "Shapes/sphere.h"
#include "camera.h"
#include "Materials/basicMaterial.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    const int width = 256;
    const int height = 256;
    const int wMult = 4;
    const int hMult = 2;
    const int derivedWidth = width * wMult;
    const int derivedHeight = height * hMult;

    //Image<float> image(derivedWidth, derivedHeight);

    Scene<float> mainScene{};

    BasicMaterial<float> testMat1 = BasicMaterial<float>();
    testMat1.basicColor = Color(255, 0, 0);
    Sphere<float> testSphere1 = Sphere<float>();
    testSphere1.radius = 5;
    testSphere1.center = Vector3<float>(0, 0, 0);
    testSphere1.material = &testMat1;
    mainScene.targets.push_back(&testSphere1);

    BasicMaterial<float> testMat2 = BasicMaterial<float>();
    testMat2.basicColor = Color(0, 255, 0);
    Sphere<float> testSphere2 = Sphere<float>();
    testSphere2.radius = 5;
    testSphere2.center = Vector3<float>(0, 5, 25);
    testSphere2.material = &testMat2;
    mainScene.targets.push_back(&testSphere2);

    BasicMaterial<float> testMat3 = BasicMaterial<float>();
    testMat3.basicColor = Color(0, 0, 255);
    Sphere<float> testSphere3 = Sphere<float>();
    testSphere3.radius = 5;
    testSphere3.center = Vector3<float>(5, 0, 15);
    testSphere3.material = &testMat3;
    mainScene.targets.push_back(&testSphere3);

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