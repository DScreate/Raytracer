
#ifndef LEWIS_PERLIN_H
#define LEWIS_PERLIN_H

double bias(double a, double b);

double gain(double a, double b);

double noise1(double arg);

double noise2(double vec[]);

double noise3(double vec[]);

double noise(double vec[], int len);

double turbulence(double *v, double freq);

#endif