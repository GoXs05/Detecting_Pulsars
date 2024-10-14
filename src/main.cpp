#include <iostream>
#include <vector>
#include "fft.h"
#include "wavelet.h"
#include "denoising.h"
#include "utils.h"
#include <filesystem>

int main() {
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;


    // Step 1: Load the dataset
    std::string filename = "../data/pulsar_data.csv";  // Path to your dataset
    std::vector<std::vector<double>> data = readCSV(filename);

    if (data.empty()) {
        std::cerr << "Error: Could not load the data." << std::endl;
        return -1;
    }
    
    std::cout << "Data successfully loaded!" << std::endl;
    std::cout << "Total records: " << data.size() << std::endl;

    // Step 2: Preprocess the data (e.g., normalize, denoise)
    std::cout << "Preprocessing data..." << std::endl;
    std::vector<std::vector<double>> cleanedData = denoiseData(data);
    
    // Step 3: Apply Fourier Transform (FFT)
    std::cout << "Applying FFT to detect periodic signals..." << std::endl;
    for (size_t i = 0; i < cleanedData.size(); ++i) {
        std::vector<double> frequencyData = applyFFT(cleanedData[i]);

        // Display the result of the FFT for the first row of data
        if (i == 0) {
            std::cout << "FFT result for the first row: " << std::endl;
            for (const auto& freq : frequencyData) {
                std::cout << freq << " ";
            }
            std::cout << std::endl;
        }
    }

    // Step 4: Apply Wavelet Transform
    std::cout << "Applying Wavelet Transform for time-frequency analysis..." << std::endl;
    for (size_t i = 0; i < cleanedData.size(); ++i) {
        std::vector<double> waveletData = applyWaveletTransform(cleanedData[i]);

        // Display the result of the wavelet transform for the first row of data
        if (i == 0) {
            std::cout << "Wavelet transform result for the first row: " << std::endl;
            for (const auto& wave : waveletData) {
                std::cout << wave << " ";
            }
            std::cout << std::endl;
        }
    }

    // Step 5: Signal detection logic (custom logic to detect pulsar signals)
    std::cout << "Detecting pulsar signals..." << std::endl;
    int pulsarCount = 0;
    for (const auto& row : cleanedData) {
        bool isPulsar = detectPulsarSignal(row);  // Custom detection logic
        if (isPulsar) {
            pulsarCount++;
        }
    }
    
    std::cout << "Total pulsars detected: " << pulsarCount << std::endl;

    return 0;
}
