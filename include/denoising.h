#ifndef DENOISING_H
#define DENOISING_H

#include <vector>

// Function to denoise time series data using a simple moving average filter
std::vector<std::vector<double>> denoiseData(const std::vector<std::vector<double>>& data);

#endif