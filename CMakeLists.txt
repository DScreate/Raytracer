cmake_minimum_required(VERSION 3.15)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Raytracer main.cpp Helpers/Space/vector2.cpp Helpers/Space/vector2.h Helpers/Space/vector3.cpp Helpers/Space/vector3.h Helpers/Space/hvector.cpp Helpers/Space/hvector.h Helpers/Matrices/transform.cpp Helpers/Matrices/transform.h Helpers/rgb.cpp Helpers/rgb.h Helpers/image.cpp Helpers/image.h ray.cpp ray.h target.cpp target.h Intersection.cpp Intersection.h Helpers/Space/apoint.cpp Helpers/Space/apoint.h Helpers/Space/point2.cpp Helpers/Space/point2.h Helpers/Space/point3.cpp Helpers/Space/point3.h halfspace.cpp halfspace.h camera.cpp camera.h scene.cpp scene.h radiance.cpp radiance.h shader.cpp shader.h luminaire.cpp luminaire.h)