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
#include "Shapes/triangle.h"

int main() {
    std::cout << "Starting up Raytracer" << std::endl;
    const int width = 256;
    const int height = 256;
    const int wMult = 4;
    const int hMult = 4;
    const int derivedWidth = width * wMult;
    const int derivedHeight = height * hMult;

    std::cout << "Setting up Scene and Targets" << std::endl;

    Scene<double> mainScene{};
    mainScene.backgroundRadiance = Color(.45, .55, .75);
    mainScene.shadowMode = hard;
    //mainScene.backgroundRadiance = Color(.045, .055, .075);

    DiffuseShader<double> redMat = DiffuseShader<double>();
    redMat.reflectivity = Color(1, 0, 0);
    redMat.specularExponent = 250;
    redMat.Ks = 0.15;
    redMat.Kd = 0.7;

    DiffuseShader<double> greenMat = DiffuseShader<double>();
    greenMat.reflectivity = Color(0, 1, 0);
    greenMat.specularExponent = 0.5;
    greenMat.Ks = 0.05;
    greenMat.Kd = 0.7;

    DiffuseShader<double> blueMat = DiffuseShader<double>();
    blueMat.reflectivity = Color(0, 0, 1);
    blueMat.specularExponent = 2;
    blueMat.Ks = 0.15;
    blueMat.Kd = 0.7;

    DiffuseShader<double> noColorDiffuse = DiffuseShader<double>();
    noColorDiffuse.reflectivity = Color(0, 0, 0);

    Reflector<double> pureRef = Reflector<double>();
    pureRef.reflectivity = Color(1, 1, 1);

    Reflector<double> copper = Reflector<double>();
    copper.reflectivity = Color(0.72, 0.45, 0.20);
    copper.specularExponent = 10;
    copper.Ks = 0.35;
    copper.Kd = 0.4;

    Reflector<double> silver = Reflector<double>();
    silver.reflectivity = Color(0.753, 0.753, 0.753);
    silver.specularExponent = 15;
    silver.Ks = 0.55;
    silver.Kd = 0.4;

    Reflector<double> gold = Reflector<double>();
    gold.reflectivity = Color(static_cast<const double &>(212. / 255.), static_cast<const double &>(175. / 255.),
                              static_cast<const double &>(55. / 255.));
    gold.specularExponent = 5;
    gold.Ks = 0.25;
    gold.Kd = 0.1;

    Dielectric<double> glass = Dielectric<double>();
    glass.reflectivity = Color(.0, .0, .0); // Added faint amount of color to allow for viewing in scene
    //glass.refractiveIndex = 1.03;
    glass.refractiveIndex = 1.517;
    glass.specularExponent = 50;
    glass.Ks = 0.45;
    glass.Kd = 0.85;

    Dielectric<double> water = Dielectric<double>();
    water.reflectivity = Color(.1, .1, .1);
    //glass.refractiveIndex = 1.03;
    water.refractiveIndex = 1.333333;
    water.specularExponent = 75;
    water.Ks = 0.45;
    water.Kd = 0.85;


    Sphere<double> redSphere1 = Sphere<double>();
    redSphere1.radius = 2;
    redSphere1.center = Vector3<double>(7, 2, 18);
    redSphere1.material.push_back(&redMat);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(redSphere1));


    Sphere<double> testSphere2 = Sphere<double>();
    testSphere2.radius = 2;
    testSphere2.center = Vector3<double>(3, 2, 17);
    testSphere2.material.push_back(&copper);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(testSphere2));


    Sphere<double> testSphere3 = Sphere<double>();
    testSphere3.radius = 5;
    testSphere3.center = Vector3<double>(-10, 5, 15);
    testSphere3.material.push_back(&blueMat);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(testSphere3));

    Sphere<double> bigSphere2 = Sphere<double>();
    bigSphere2.radius = 10;
    bigSphere2.center = Vector3<double>(8, 10, -5);
    bigSphere2.material.push_back(&copper);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(bigSphere2));

    Sphere<double> testSphere4 = Sphere<double>();
    testSphere4.radius = 5;
    testSphere4.center = Vector3<double>(4, 5, 10);
    testSphere4.material.push_back(&silver);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(testSphere4));


    Sphere<double> testSphere5 = Sphere<double>();
    testSphere5.radius = 8;
    testSphere5.center = Vector3<double>(-12, 8, -10);
    testSphere5.material.push_back(&gold);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(testSphere5));


    Sphere<double> glassSphere = Sphere<double>();
    glassSphere.radius = 2;
    glassSphere.center = Vector3<double>(-3, 2, 0);
    glassSphere.material.push_back(&glass);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(glassSphere));

    Sphere<double> glassSphereBig = Sphere<double>();
    glassSphereBig.radius = 4;
    glassSphereBig.center = Vector3<double>(-1, 4, 20);
    glassSphereBig.material.push_back(&glass);
    mainScene.targets.push_back(std::make_unique<Sphere<double>>(glassSphereBig));


    // TODO: Investigate why y direction seems inverted
    Triangle<double> redTriangle = Triangle<double>(
            Vector3<double>(30, 0, -30),
            Vector3<double>(-30, 0, -30),
            Vector3<double>(-30, 0, 30));
    redTriangle.material.push_back(&redMat);
    mainScene.targets.push_back(std::make_unique<Triangle<double>>(redTriangle));

    Triangle<double> greenTriangle = Triangle<double>(
            Vector3<double>(-30, 0, 30),
            Vector3<double>(30, 0, 30),
            Vector3<double>(30, 0, -30));
    greenTriangle.material.push_back(&greenMat);
    mainScene.targets.push_back(std::make_unique<Triangle<double>>(greenTriangle));


    Luminaire<double> testLumn = Luminaire<double>();
    testLumn.position = Vector3<double>(-200, 200, 300);
    //testLumn.position = Vector3<double>(-50, 50, 20);
    //testLumn.position = Vector3<double>(0, 20, -300);
    testLumn.intensity = 1.8;
    mainScene.luminaires.push_back(std::make_unique<Luminaire<double>>(testLumn));


    Luminaire<double> pinkLumn = Luminaire<double>();
    pinkLumn.position = Vector3<double>(70, 25, 150);
    pinkLumn.intensity = 2.8f;
    pinkLumn.lightColor = Color(0.8, 0.1, 0.65);
    mainScene.luminaires.push_back(std::make_unique<Luminaire<double>>(pinkLumn));

    Vector3<double> camPosition = Vector3<double>(0, 60, 50);
    //Vector3<double> camPosition = Vector3<double>(25, 50, 37);
    //Vector3<double> camPosition = Vector3<double>(0, 0, 0);
    //Vector3<double> camPosition = Vector3<double>(-15, 15, 45);
    //Vector3<double> camPosition = Vector3<double>(-15, 45, 35);

    Vector3<double> camLookAt = Vector3<double>(0, 0, 0);
    Vector3<double> camViewUp = Vector3<double>(0, 1, 0);

    Camera<double> mainCam = Camera<double>(camPosition, camLookAt, camViewUp);
    mainCam.fov = 47.0;
    mainCam.antiAliasSampling = uniform;
    mainCam.antiAliasFactor = 4;
    mainCam.dof = true;
    mainCam.dofSamples = 1;
    mainCam.dofFactor = 4;
    mainCam.focalLength = 1;

    std::cout << "Running calculations" << std::endl;

    // put result into image
    Image<double> outputImage = mainCam.renderImage(&mainScene, derivedWidth, derivedHeight);

    outputImage.output();
    return 0;
}