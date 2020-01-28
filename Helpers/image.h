//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include <vector>
#include <fstream>
#include <iostream>
#include "rgb.h"

/*
 * Image class for display pixel data
 * General design sourced from
 * "Fundamentals of Computer Graphics, 4th Edition" by Steve Marschner and Peter Shirley
 * pp. 9
 */
typedef RGB<int> Color;

template<class T>
class Image {
public:
    int width;
    int height;

    std::vector<Color> pixels;
    Image(): width(256), height(256), pixels(256 * 256) {};

    Image(int _width, int _height): width(_width), height(_height), pixels(_width * _height) {}

    //Image(): RGB<T>(RGB<T>() = {}) {};

    void initDummyData();
    Color* getPixel(int x, int y);
    void setPixel(int x, int y, const Color& rgb);
    void output();
};


// TODO: Figure out why image is repeated/misshapen on non 256x256 images
template<class T>
void Image<T>::output() {
    std::ofstream imageFile;
    imageFile.open("image.ppm", std::ios::trunc);

    if (imageFile.is_open()) {
        std::cout << "File is open, now trying to print image" << std::endl;
        // header of ppm file
        imageFile << "P3" << std::endl;
        imageFile << width << " " << height << std::endl;
        imageFile << "255" << std::endl;
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                Color* rgb = getPixel(x, y);
                imageFile << rgb->r << " " << rgb->g << " " << rgb->b << std::endl;
            }
        }

        std::cout << "Printing complete, now closing file" << std::endl;
        imageFile.close();
    }
}

template<class T>
Color* Image<T>::getPixel(int x, int y) {
    return &this->pixels[x + (y * width)];
}

template<class T>
void Image<T>::setPixel(int x, int y, const Color& rgb) {
    *this->getPixel(x, y) = rgb;
}

template<class T>
void Image<T>::initDummyData() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int _x = x % 255;
            int _y = y % 255;
            this->setPixel(x, y, Color(_x % 255, _y % 255, 0));
            /*
            0   255   0 // green
            0   0   255 // blue
            255   255   0 //yellow
            255   255   255 //white
            0   0   0 //black
             */
        }
    }
}


#endif //RAYTRACER_IMAGE_H
