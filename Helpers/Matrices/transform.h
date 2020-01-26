//
// Created by tessa on 1/23/20.
//

#ifndef RAYTRACER_TRANSFORM_H
#define RAYTRACER_TRANSFORM_H


class transform {
    public:

        float[][] components[4][4];
        transform operator*=(transform that);
};


#endif //RAYTRACER_TRANSFORM_H
