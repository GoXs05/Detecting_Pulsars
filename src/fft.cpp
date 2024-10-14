#define _USE_MATH_DEFINES
#include <cmath>

#include "fft.h"

#include <iostream>
#include <complex>
#include <vector>

// Simple FFT function implementation   
std::vector<double> applyFFT(const std::vector<double>& data) {
    size_t n = data.size();
    std::vector<std::complex<double>> X(n);

    // Perform a basic Cooley-Tukey FFT (assuming n is a power of 2 for simplicity)
    for (size_t k = 0; k < n; ++k) {
        std::complex<double> sum(0.0, 0.0);
        for (size_t t = 0; t < n; ++t) {
            double angle = -2 * M_PI * t * k / n;
            sum += std::polar(1.0, angle) * data[t];
        }
        X[k] = sum;
    }

    // Convert the complex values to their magnitudes
    std::vector<double> magnitudes(n);
    for (size_t i = 0; i < n; ++i) {
        magnitudes[i] = std::abs(X[i]);
    }

    return magnitudes;
}
