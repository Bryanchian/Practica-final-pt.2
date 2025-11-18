#include <stdio.h>
#include <math.h>
#include "funciones.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    double y0 = 1.0;
    double x = 10.0;
    double v = 20.0;
    double theta = 45.0 * M_PI / 180.0;

    double result = yf(y0, x, v, theta);

    printf("Ejemplo de uso de la libreria:\n");
    printf("yf = %f\n", result);

    double r = normal(0.0, 1.0);
    printf("Ejemplo de numero normal: %f\n", r);

    return 0;
}


