#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(int argc, char *argv[]) {
    if (argc != 10) return 1;

    double y0 = atof(argv[1]);
    double x = atof(argv[2]);
    double v0 = atof(argv[3]);
    double dv0 = atof(argv[4]);
    double theta0 = atof(argv[5]) * M_PI / 180.0;
    double dtheta = atof(argv[6]) * M_PI / 180.0;
    long N = atol(argv[7]);
    int Nbins = atoi(argv[8]);
    long seed = atol(argv[9]);

    srand48(seed);

    double *Y = malloc(N * sizeof(double));
    int *hist = calloc(Nbins, sizeof(int));
    if (!Y || !hist) return 1;

    for (long i = 0; i < N; i++) {
        double v_i = normal(v0, dv0);
        double theta_i = normal(theta0, dtheta);
        Y[i] = yf(y0, x, v_i, theta_i);
    }

    double sum = 0;
    for (long i = 0; i < N; i++) sum += Y[i];
    double mean = sum / N;

    double var = 0;
    for (long i = 0; i < N; i++) var += (Y[i] - mean) * (Y[i] - mean);
    var /= N;
    double std = sqrt(var);

    double min = Y[0], max = Y[0];
    for (long i = 1; i < N; i++) {
        if (Y[i] < min) min = Y[i];
        if (Y[i] > max) max = Y[i];
    }

    double binw = (max - min) / Nbins;

    for (long i = 0; i < N; i++) {
        int b = (int)((Y[i] - min) / binw);
        if (b == Nbins) b--;
        hist[b]++;
    }

    for (int i = 0; i < Nbins; i++) {
        double a = min + i * binw;
        double b = a + binw;
        printf("%.5f %.5f %d\n", a, b, hist[i]);
    }

    printf("Media %.6f\n", mean);
    printf("Desviacion %.6f\n", std);

    free(Y);
    free(hist);
    return 0;
}


