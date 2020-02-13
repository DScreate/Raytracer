//
// Created by tessa on 2/11/20.
//

#ifndef RAYTRACER_RANDOM_H
#define RAYTRACER_RANDOM_H

#include <random>
#include <functional>

// Reference: http://www.cplusplus.com/reference/random/

template<class T>
T makeRandom() {
    static std::uniform_real_distribution<T> rand(0.0, 1.0);
    static std::default_random_engine generator;
    static std::function<T()> rand_generator = std::bind(rand, generator);
    return rand_generator();
}

#endif //RAYTRACER_RANDOM_H
