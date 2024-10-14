#include "wavelet.h"
#include <vector>
#include <cmath>

// Simple implementation of the Haar wavelet transform
std::vector<double> applyWaveletTransform(const std::vector<double>& data) {
    size_t n = data.size();
    std::vector<double> waveletData = data;

    // Perform the Haar wavelet transform
    while (n > 1) {
        std::vector<double> temp(n / 2);
        for (size_t i = 0; i < n / 2; ++i) {
            temp[i] = (waveletData[2 * i] + waveletData[2 * i + 1]) / std::sqrt(2.0);  // Average
            waveletData[i] = (waveletData[2 * i] - waveletData[2 * i + 1]) / std::sqrt(2.0);  // Difference
        }
        std::copy(temp.begin(), temp.end(), waveletData.begin() + n / 2);
        n /= 2;
    }

    return waveletData;
}
