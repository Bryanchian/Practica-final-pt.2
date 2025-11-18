#include <stdio.h>
#include "funciones.h"

int main() {
    double coef[] = {1.5, -2.0, 3.5};
    double x[] = {2.0, -1.0};
    double y_pred = predict(coef, x, 2);

    printf("Prediccion: %.4f\n", y_pred);

    double y0 = 1.0;
    double X = 10.0;
    double v = 20.0;
    double theta = 45.0 * M_PI / 180.0;

    double y_final = yf(y0, X, v, theta);
    printf("Tiro parabolico y_f = %.4f\n", y_final);

    return 0;
}
