#include <math.h>

double predict(double coef[], double x[], int n) {
    double y = coef[0];
    for (int i = 0; i < n; i++) y += coef[i + 1] * x[i];
    return y;
}

double yf(double y0, double x, double v, double theta_rad) {
    double t = x / (v * cos(theta_rad));
    return y0 + v * sin(theta_rad) * t - 0.5 * 9.81 * t * t;
}
