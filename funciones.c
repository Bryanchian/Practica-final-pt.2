#include <math.h>
#include <stdlib.h>
#include "funciones.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double normal(double mean, double stddev) {
    double r = drand48();
    double q = drand48();
    double R = sqrt(-2.0 * log(r));
    return mean + stddev * R * cos(2.0 * M_PI * q);
}

double yf(double y0, double x, double v, double theta) {
    double t = x / (v * cos(theta));
    return y0 + v * sin(theta) * t - 0.5 * 9.81 * t * t;
}

