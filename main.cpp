#include <iostream>
#include "Helpers/image.h"
#include "scene.h"
#include "Shapes/sphere.h"
#include "camera.h"
#include "Materials/basicMaterial.h"
#include "Materials/diffuserShader.h"
#include "Materials/surfaceNormalMaterial.h"

int main() {
    std::cout << "Starting up Raytracer" << std::endl;
    const int width = 256;
    const int height = 256;
    const int wMult = 4;
    const int hMult = 4;
    const int derivedWidth = width * wMult;
    const int derivedHeight = height * hMult;

    //Image<float> image(derivedWidth, derivedHeight);
    std::cout << "Setting up Scene and Targets" << std::endl;

    Scene<float> mainScene{};
    mainScene.backgroundRadiance = Color(.65, .75, .95);

    DiffuseShader<float> testMat1 = DiffuseShader<float>();
    testMat1.reflectivity = Color(1, 0, 0);
    Sphere<float> testSphere1 = Sphere<float>();
    testSphere1.radius = 5;
    testSphere1.center = Vector3<float>(0, 0, -10);
    testSphere1.material = &testMat1;
    mainScene.targets.push_back(&testSphere1);


    DiffuseShader<float> testMat2 = DiffuseShader<float>();
    testMat2.reflectivity = Color(0, 1, 0);
    Sphere<float> testSphere2 = Sphere<float>();
    testSphere2.radius = 2;
    testSphere2.center = Vector3<float>(-3, 0, 15);
    testSphere2.material = &testMat2;
    mainScene.targets.push_back(&testSphere2);


    DiffuseShader<float> testMat3 = DiffuseShader<float>();
    testMat3.reflectivity = Color(0, 0, 1);
    Sphere<float> testSphere3 = Sphere<float>();
    testSphere3.radius = 5;
    testSphere3.center = Vector3<float>(15, 0, 15);
    testSphere3.material = &testMat3;
    mainScene.targets.push_back(&testSphere3);

    DiffuseShader<float> testMat4 = DiffuseShader<float>();
    testMat4.reflectivity = Color(0, 0.8f, 0.55f);
    Sphere<float> bigSphere = Sphere<float>();
    bigSphere.radius = 100;
    bigSphere.center = Vector3<float>(0, -105, -1);
    bigSphere.material = &testMat4;
    mainScene.targets.push_back(&bigSphere);

    Sphere<float> bigSphere2 = Sphere<float>();
    bigSphere2.radius = 15;
    bigSphere2.center = Vector3<float>(-2, 25, -1);
    bigSphere2.material = &testMat1;
    mainScene.targets.push_back(&bigSphere2);

    /*
    for (int i = 0; i < 12; i++) {
        BasicMaterial<float> randMat = *new BasicMaterial<float>();
        auto randColor = new Color(int(255 * makeRandom<float>()), int(255 * makeRandom<float>()), int(255 * makeRandom<float>()));
        testMat1.basicColor = *randColor;
        auto* randSphere = new Sphere<float>();
        testSphere1.radius = 25;
        testSphere1.center = *new Vector3<float>(makeRandom<float>() * 10.0f, makeRandom<float>() * 10.0f, makeRandom<float>() * 10.0f);
        testSphere1.material = &randMat;
        mainScene.targets.push_back(randSphere);
    }
    */

    Luminaire<float> testLumn = Luminaire<float>();
    testLumn.position = Vector3<float>(0, 0, 0);
    testLumn.intensity = 5.f;
    mainScene.luminaires.push_back(&testLumn);

    Luminaire<float> testLumn1 = Luminaire<float>();
    testLumn1.position = Vector3<float>(30, 20, 10);
    testLumn1.intensity = 5.f;
    //testLumn1.lightColor = Color(0.9, 0.0, 0.8);
    //mainScene.luminaires.push_back(&testLumn1);

    //Vector3<float> camPosition = Vector3<float>(0, 0, 50);
    Vector3<float> camPosition = Vector3<float>(50, 100, 75);
    //Vector3<float> camPosition = Vector3<float>(0, 0, 0);

    Vector3<float> camLookAt = Vector3<float>(0, 0, 0);
    Vector3<float> camViewUp = Vector3<float>(0, 1, 0);

    Camera<float> mainCam = Camera<float>(camPosition, camLookAt, camViewUp);
    mainCam.fov = 47.0f;
    mainCam.antiAlias = false;
    mainCam.antiAliasFactor = 8;
    mainCam.dof = false;
    mainCam.dofSamples = 4;

    std::cout << "Running calculations" << std::endl;

    // put result into image
    Image<float> outputImage = mainCam.renderImage(mainScene, derivedWidth, derivedHeight);

    //image.initDummyData();
    outputImage.output();
    return 0;
}