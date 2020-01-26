cmake_minimum_required(VERSION 3.15)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Raytracer main.cpp Helpers/Vectors/Vector2.cpp Helpers/Vectors/Vector2.h Helpers/Vectors/Vector3.cpp Helpers/Vectors/Vector3.h Helpers/Vectors/avector.cpp Helpers/Vectors/avector.h Helpers/Vectors/hvector.cpp Helpers/Vectors/hvector.h Helpers/Matrices/transform.cpp Helpers/Matrices/transform.h Helpers/rgb.cpp Helpers/rgb.h Helpers/image.cpp Helpers/image.h)