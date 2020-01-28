#include <iostream>
#include <fstream>
#include "Helpers/image.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    int i;

    Image<float> image(256, 256);
    image.initDummyData();
    image.output();
    /*
     * for each pixel
     *  compute viewing ray
     *  intersect ray with scene
     *  compute illumination at visible point
     *  put result into image
     */
    return 0;
}