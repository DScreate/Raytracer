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

    //Image<double> image(derivedWidth, derivedHeight);
    std::cout << "Setting up Scene and Targets" << std::endl;

    Scene<double> mainScene{};
    //mainScene.backgroundRadiance = Color(.45, .55, .75);
    mainScene.backgroundRadiance = Color(.045, .055, .075);

    DiffuseShader<double> redMat = DiffuseShader<double>();
    redMat.reflectivity = Color(1, 0, 0);

    DiffuseShader<double> greenMat = DiffuseShader<double>();
    greenMat.reflectivity = Color(0, 1, 0);

    DiffuseShader<double> noColorDiffuse = DiffuseShader<double>();
    noColorDiffuse.reflectivity = Color(0, 0, 0);

    Reflector<double> pureRef = Reflector<double>();
    pureRef.reflectivity = Color(1, 1, 1);

    Reflector<double> copper = Reflector<double>();
    copper.reflectivity = Color(0.72, 0.45, 0.20);

    Reflector<double> silver = Reflector<double>();
    silver.reflectivity = Color(0.753, 0.753, 0.753);

    Reflector<double> gold = Reflector<double>();
    gold.reflectivity = Color(static_cast<const double &>(212. / 255.), static_cast<const double &>(175. / 255.),
                              static_cast<const double &>(55. / 255.));


    Dielectric<double> glass = Dielectric<double>();
    glass.reflectivity = Color(.1, .1, .1);
    //glass.refractiveIndex = double(1);
    glass.refractiveIndex = 1.517;

    Sphere<double> redSphere1 = Sphere<double>();
    redSphere1.radius = 5;
    redSphere1.center = Vector3<double>(0, 0, -10);
    redSphere1.material.push_back(&redMat);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(redSphere1));


    Sphere<double> testSphere2 = Sphere<double>();
    testSphere2.radius = 2;
    testSphere2.center = Vector3<double>(-3, -3, 15);
    testSphere2.material.push_back(&greenMat);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(testSphere2));


    DiffuseShader<double> testMat3 = DiffuseShader<double>();
    testMat3.reflectivity = Color(0, 0, 1);
    Sphere<double> testSphere3 = Sphere<double>();
    testSphere3.radius = 5;
    testSphere3.center = Vector3<double>(15, 8, 15);
    testSphere3.material.push_back(&testMat3);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(testSphere3));


    Sphere<double> bigSphere = Sphere<double>();
    bigSphere.radius = 100;
    bigSphere.center = Vector3<double>(0, -105, -1);
    bigSphere.material.push_back(&copper);
    //bigSphere.material.push_back(&noColorDiffuse);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(bigSphere));

    Sphere<double> bigSphere2 = Sphere<double>();
    bigSphere2.radius = 10;
    bigSphere2.center = Vector3<double>(-2, 20, -1);
    bigSphere2.material.push_back(&silver);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(bigSphere2));

    Sphere<double> testSphere4 = Sphere<double>();
    testSphere4.radius = 5;
    testSphere4.center = Vector3<double>(5, 0, 5);
    testSphere4.material.push_back(&silver);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(testSphere4));


    Sphere<double> testSphere5 = Sphere<double>();
    testSphere5.radius = 8;
    testSphere5.center = Vector3<double>(-12, 7, -10);
    testSphere5.material.push_back(&gold);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(testSphere5));


    Sphere<double> glassSphere = Sphere<double>();
    glassSphere.radius = 4;
    glassSphere.center = Vector3<double>(-5, 1, 8);
    glassSphere.material.push_back(&glass);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(glassSphere));

    Sphere<double> glassSphereBig = Sphere<double>();
    glassSphereBig.radius = 6;
    glassSphereBig.center = Vector3<double>(6, 4, -14);
    glassSphereBig.material.push_back(&glass);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(glassSphereBig));

    Luminaire<double> testLumn = Luminaire<double>();
    //testLumn.position = Vector3<double>(0, 0, 0);
    testLumn.position = Vector3<double>(-50, 250, 300);
    //testLumn.position = Vector3<double>(0, 20, -300);


    testLumn.intensity = 3.f;
    mainScene.luminaires.push_back(std::make_unique<Luminaire<double>>(testLumn));

    Luminaire<double> testLumn1 = Luminaire<double>();
    testLumn1.position = Vector3<double>(0, 0, 100);
    testLumn1.intensity = 5.f;
    //testLumn1.lightColor = Color(0.9, 0.0, 0.8);
    //mainScene.luminaires.push_back(&testLumn1);

    Vector3<double> camPosition = Vector3<double>(0, 0, 50);
    //Vector3<double> camPosition = Vector3<double>(50, 100, 75);
    //Vector3<double> camPosition = Vector3<double>(0, 0, 0);
    //Vector3<double> camPosition = Vector3<double>(-15, 15, 45);
    //Vector3<double> camPosition = Vector3<double>(-15, 45, 35);

    Vector3<double> camLookAt = Vector3<double>(0, 0, 0);
    Vector3<double> camViewUp = Vector3<double>(0, 1, 0);

    Camera<double> mainCam = Camera<double>(camPosition, camLookAt, camViewUp);
    mainCam.fov = 47.0;
    mainCam.antiAlias = false;
    mainCam.antiAliasFactor = 4;
    mainCam.dof = false;
    mainCam.dofSamples = 4;

    std::cout << "Running calculations" << std::endl;

    // put result into image
    Image<double> outputImage = mainCam.renderImage(&mainScene, derivedWidth, derivedHeight);

    //image.initDummyData();
    outputImage.output();
    return 0;
}