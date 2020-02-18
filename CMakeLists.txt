cmake_minimum_required(VERSION 3.15)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)
file(GLOB SOURCES
        *.h
        *.cpp
        )

add_executable(Raytracer ${SOURCE_FILES} ${SOURCES} Helpers/typedefs.h Materials/material.h Materials/shader.h Lighting/luminaire.h Materials/basicMaterial.h Materials/diffuserShader.h Lighting/directionalLuminaire.h Helpers/random.h Materials/reflector.h Materials/dielectric.h Lighting/pointLuminaire.h Shapes/triangle.h)