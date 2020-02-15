#include <iostream>
#include "Helpers/image.h"
#include "scene.h"
#include "Shapes/sphere.h"
#include "camera.h"
#include "Materials/basicMaterial.h"
#include "Materials/diffuserShader.h"
#include "Materials/surfaceNormalMaterial.h"
#include "Materials/reflector.h"
#include "Materials/dielectric.h"

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
    mainScene.backgroundRadiance = Color(.45, .55, .75);

    DiffuseShader<float> testMat1 = DiffuseShader<float>();

    DiffuseShader<float> noColorDiffuse = DiffuseShader<float>();
    noColorDiffuse.reflectivity = Color(0, 0, 0);

    testMat1.reflectivity = Color(1, 0, 0);
    Sphere<float> testSphere1 = Sphere<float>();
    testSphere1.radius = 5;
    testSphere1.center = Vector3<float>(0, 0, -10);
    testSphere1.material.push_back(&testMat1);
    mainScene.targets.push_back(&testSphere1);


    Reflector<float> pureRef = Reflector<float>();
    pureRef.reflectivity = Color(1, 1, 1);

    Reflector<float> copper = Reflector<float>();
    copper.reflectivity = Color(0.72, 0.45, 0.20);

    Reflector<float> silver = Reflector<float>();
    silver.reflectivity = Color(0.753, 0.753, 0.753);

    Reflector<float> gold = Reflector<float>();
    gold.reflectivity = Color(212. / 255., 175. / 255., 55. / 255.);

    Dielectric<float> glass = Dielectric<float>();
    glass.reflectivity = Color(.1, .1, .1);
    //glass.refractiveIndex = 1.3f;
    glass.refractiveIndex = 1.517f;

    DiffuseShader<float> testMat2 = DiffuseShader<float>();
    testMat2.reflectivity = Color(0, 1, 0);
    Sphere<float> testSphere2 = Sphere<float>();
    testSphere2.radius = 2;
    testSphere2.center = Vector3<float>(-3, -5, 15);
    testSphere2.material.push_back(&testMat2);
    mainScene.targets.push_back(&testSphere2);


    DiffuseShader<float> testMat3 = DiffuseShader<float>();
    testMat3.reflectivity = Color(0, 0, 1);
    Sphere<float> testSphere3 = Sphere<float>();
    testSphere3.radius = 5;
    testSphere3.center = Vector3<float>(15, 8, 15);
    testSphere3.material.push_back(&testMat3);
    mainScene.targets.push_back(&testSphere3);


    Sphere<float> bigSphere = Sphere<float>();
    bigSphere.radius = 100;
    bigSphere.center = Vector3<float>(0, -105, -1);
    bigSphere.material.push_back(&copper);
    //bigSphere.material.push_back(&noColorDiffuse);
    mainScene.targets.push_back(&bigSphere);

    Sphere<float> bigSphere2 = Sphere<float>();
    bigSphere2.radius = 10;
    bigSphere2.center = Vector3<float>(-2, 20, -1);
    bigSphere2.material.push_back(&silver);
    mainScene.targets.push_back(&bigSphere2);

    Sphere<float> testSphere4 = Sphere<float>();
    testSphere4.radius = 5;
    testSphere4.center = Vector3<float>(5, 0, 5);
    testSphere4.material.push_back(&silver);
    mainScene.targets.push_back(&testSphere4);


    Sphere<float> testSphere5 = Sphere<float>();
    testSphere5.radius = 8;
    testSphere5.center = Vector3<float>(-12, 7, -10);
    testSphere5.material.push_back(&gold);
    mainScene.targets.push_back(&testSphere5);

    Sphere<float> glassSphere = Sphere<float>();
    glassSphere.radius = 4;
    glassSphere.center = Vector3<float>(-5, -1, 8);
    glassSphere.material.push_back(&glass);
    mainScene.targets.push_back(&glassSphere);


    Luminaire<float> testLumn = Luminaire<float>();
    //testLumn.position = Vector3<float>(-25, 45, 35);
    testLumn.position = Vector3<float>(-50, 250, 300);

    testLumn.intensity = 3.f;
    mainScene.luminaires.push_back(&testLumn);

    Luminaire<float> testLumn1 = Luminaire<float>();
    testLumn1.position = Vector3<float>(0, 0, 100);
    testLumn1.intensity = 5.f;
    //testLumn1.lightColor = Color(0.9, 0.0, 0.8);
    //mainScene.luminaires.push_back(&testLumn1);

    //Vector3<float> camPosition = Vector3<float>(0, 0, 50);
    //Vector3<float> camPosition = Vector3<float>(50, 100, 75);
    //Vector3<float> camPosition = Vector3<float>(0, 0, 0);
    Vector3<float> camPosition = Vector3<float>(-15, 15, 45);
    //Vector3<float> camPosition = Vector3<float>(-15, 45, 35);

    Vector3<float> camLookAt = Vector3<float>(0, 0, 0);
    Vector3<float> camViewUp = Vector3<float>(0, 1, 0);

    Camera<float> mainCam = Camera<float>(camPosition, camLookAt, camViewUp);
    mainCam.fov = 47.0;
    mainCam.antiAlias = true;
    mainCam.antiAliasFactor = 4;
    mainCam.dof = false;
    mainCam.dofSamples = 4;

    std::cout << "Running calculations" << std::endl;

    // put result into image
    Image<float> outputImage = mainCam.renderImage(mainScene, derivedWidth, derivedHeight);

    //image.initDummyData();
    outputImage.output();
    return 0;
}