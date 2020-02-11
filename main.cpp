#include <iostream>
#include "Helpers/image.h"
#include "scene.h"
#include "Shapes/sphere.h"
#include "camera.h"
#include "Materials/basicMaterial.h"
#include "Materials/diffuserShader.h"

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


    DiffuseShader<float> testMat1 = DiffuseShader<float>();
    testMat1.reflectivity = Color(255, 0, 0);
    Sphere<float> testSphere1 = Sphere<float>();
    testSphere1.radius = 5;
    testSphere1.center = Vector3<float>(0, 0, 0);
    testSphere1.material = &testMat1;
    mainScene.targets.push_back(&testSphere1);

    DiffuseShader<float> testMat2 = DiffuseShader<float>();
    testMat2.reflectivity = Color(0, 255, 0);
    Sphere<float> testSphere2 = Sphere<float>();
    testSphere2.radius = 5;
    testSphere2.center = Vector3<float>(0, 5, 25);
    testSphere2.material = &testMat2;
    mainScene.targets.push_back(&testSphere2);

    DiffuseShader<float> testMat3 = DiffuseShader<float>();
    testMat3.reflectivity = Color(0, 0, 255);
    Sphere<float> testSphere3 = Sphere<float>();
    testSphere3.radius = 5;
    testSphere3.center = Vector3<float>(5, 0, 15);
    testSphere3.material = &testMat3;
    mainScene.targets.push_back(&testSphere3);

    Luminaire<float> testLumn = Luminaire<float>();
    testLumn.position = Vector3<float>(-25, 0, 0);
    mainScene.luminaires.push_back(&testLumn);

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