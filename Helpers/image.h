
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

// TODO: Add "colorScale" variable to account for scales other than 0 - 255
template<class T>
class Image {
public:
    int width;
    int height;

    std::vector<Color> pixels;

    Image() : width(256), height(256), pixels(256 * 256) {};

    Image(const int _width, const int _height) : width(_width), height(_height), pixels(
            static_cast<unsigned long>(_width * _height)) {}

    //Image(): RGB<T>(RGB<T>() = {}) {};

    void initDummyData();

    [[nodiscard]] Color getPixel(int x, int y) const;

    void setPixel(int x, int y, const Color &rgb);

    Image<T> getImage(std::string fileName);

    void output(std::string fileName = "output_image.ppm");

    void initDummyFast();

    Color newGetPixel(int x, int y) const;
};

template<typename T>
T clipPixel(const T &n, const T &lower, const T &upper) {
    return std::max(lower, std::min(n, upper));
}

// TODO: Investigate why this is clipping the far left edge weirdly
template<class T>
Image<T> Image<T>::getImage(std::string fileName) {
    std::ifstream imageFile;
    imageFile.open(fileName);
    std::string magicNum;
    std::string gimpLine;;
    Image<T> resImage = Image<T>();
    T i, j;
    int r, g, b;
    if (imageFile.is_open()) {
        imageFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        imageFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        imageFile >> i >> j;
        resImage.width = i;
        resImage.height = j;
        for (int y = 0; y < resImage.height; y++) {
            for (int x = 0; x < resImage.width; x++) {
                imageFile >> r;
                imageFile >> g;
                imageFile >> b;
                Color col = Color(r / 255., g / 255., b / 255.);
                resImage.setPixel(x, y, col);
            }
        }
    }

    resImage.output("terrain output.ppm");
    return resImage;
}

template<class T>
void Image<T>::output(std::string fileName) {
    std::ofstream imageFile;
    imageFile.open(fileName, std::ios::trunc);

    if (imageFile.is_open()) {
        std::cout << "File is open, now trying to print image: " << fileName << std::endl;
        // header of ppm file
        imageFile << "P3" << std::endl;
        imageFile << width << " " << height << std::endl;
        imageFile << "255" << std::endl;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Color rgb = getPixel(x, y);
                imageFile << clipPixel(int(rgb.r * 255.99), 0, 255) << " " << clipPixel(int(rgb.g * 255.99), 0, 255)
                          << " " << clipPixel(int(rgb.b * 255.99), 0, 255) << std::endl;
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
Color Image<T>::newGetPixel(const int x, const int y) const {
    return this->pixels[x + (y * height)];
}

template<class T>
void Image<T>::setPixel(int x, int y, const Color &rgb) {
    this->pixels[x + (y * width)] = rgb;
}

template<class T>
void Image<T>::initDummyData() {
    float xRatio = (float) width / 256;
    float yRatio = (float) height / 256;
    T _x = 0;
    T _y = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            _x = static_cast<int>(T(x) / T(xRatio));
            _y = T(y) / T(yRatio);
            int _z = static_cast<int>(T(x + y) / T(xRatio + yRatio));
            this->setPixel(x, y, Color(_x / 255, _y / 255, _z / 255));
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
                _x = static_cast<int>(x / xRatio);
                _y = static_cast<int>(y / yRatio);
                int _z = static_cast<int>((x + y) / (xRatio + yRatio));
                this->setPixel(x, y, Color(_x / 255, _y / 255, _z / 255));
                Color rgb = getPixel(x, y);
                imageFile << rgb.r << " " << rgb.g << " " << rgb.b << std::endl;
            }
        }

        std::cout << "Printing complete, now closing file" << std::endl;
        imageFile.close();
    }
}


#endif //RAYTRACER_IMAGE_H
