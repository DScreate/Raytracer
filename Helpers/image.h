//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include <vector>
#include <fstream>
#include <iostream>
#include "rgb.h"
#include "typedefs.h"

/*
 * Image class for display pixel data
 * General design sourced from
 * "Fundamentals of Computer Graphics, 4th Edition" by Steve Marschner and Peter Shirley
 * pp. 9
 */

template<class T>
class Image {
public:
    int width;
    int height;

    std::vector<Color> pixels;
    Image(): width(256), height(256), pixels(256 * 256) {};

    Image(const int _width, const int _height): width(_width), height(_height), pixels(_width * _height) {}

    //Image(): RGB<T>(RGB<T>() = {}) {};

    void initDummyData();
    [[nodiscard]] Color getPixel(int x, int y) const;
    void setPixel(int x, int y, const Color& rgb);
    void output();
    void initDummyFast();
};

template<class T>
void Image<T>::output() {
    std::ofstream imageFile;
    imageFile.open("output_image.ppm", std::ios::trunc);

    if (imageFile.is_open()) {
        std::cout << "File is open, now trying to print image" << std::endl;
        // header of ppm file
        imageFile << "P3" << std::endl;
        imageFile << width << " " << height << std::endl;
        imageFile << "255" << std::endl;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Color rgb = getPixel(x, y);
                imageFile << rgb.r << " " << rgb.g << " " << rgb.b << std::endl;
            }
        }

        std::cout << "Printing complete, now closing file" << std::endl;
        imageFile.close();
    }
}

template<class T>
Color Image<T>::getPixel(const int x, const int y) const {
    return this->pixels[x + (y * width)];
}

template<class T>
void Image<T>::setPixel(int x, int y, const Color& rgb) {
    this->pixels[x + (y * width)] = rgb;
}

template<class T>
void Image<T>::initDummyData() {
    float xRatio = (float)width / 256;
    float yRatio = (float)height / 256;
    int _x = 0;
    int _y = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            _x = x / xRatio;
            _y = y / yRatio;
            int _z = (x + y) / (xRatio + yRatio);
            this->setPixel(x, y, Color(_x, _y, _z));
        }
    }
}

template<class T>
void Image<T>::initDummyFast() {


    std::ofstream imageFile;
    imageFile.open("image.ppm", std::ios::trunc);

    if (imageFile.is_open()) {
        std::cout << "File is open, now trying to print image" << std::endl;
        // header of ppm file
        imageFile << "P3" << std::endl;
        imageFile << width << " " << height << std::endl;
        imageFile << "255" << std::endl;


        float xRatio = (float)width / 256;
        float yRatio = (float)height / 256;
        int _x = 0;
        int _y = 0;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                _x = x / xRatio;
                _y = y / yRatio;
                int _z = (x + y) / (xRatio + yRatio);
                this->setPixel(x, y, Color(_x, _y, _z));
                Color rgb = getPixel(x, y);
                imageFile << rgb.r << " " << rgb.g << " " << rgb.b << std::endl;
            }
        }

        std::cout << "Printing complete, now closing file" << std::endl;
        imageFile.close();
    }
}


#endif //RAYTRACER_IMAGE_H
