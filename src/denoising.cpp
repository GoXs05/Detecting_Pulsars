#include "denoising.h"
#include <vector>
#include <numeric>  // For std::accumulate

// Simple moving average filter to denoise time series data
std::vector<double> movingAverage(const std::vector<double>& data, size_t windowSize) {
    std::vector<double> result;
    for (size_t i = 0; i <= data.size() - windowSize; ++i) {
        double avg = std::accumulate(data.begin() + i, data.begin() + i + windowSize, 0.0) / windowSize;
        result.push_back(avg);
    }
    return result;
}

// Denoising function for the entire dataset
std::vector<std::vector<double>> denoiseData(const std::vector<std::vector<double>>& data) {
    size_t windowSize = 5;  // Placeholder window size for the moving average filter
    std::vector<std::vector<double>> denoisedData;

    for (const auto& row : data) {
        denoisedData.push_back(movingAverage(row, windowSize));
    }

    return denoisedData;
}
