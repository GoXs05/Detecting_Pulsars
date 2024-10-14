#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Function to read a CSV file and store data into a 2D vector
std::vector<std::vector<double>> readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<double>> data;
    std::string line, value;

    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return data;
    }

    while (std::getline(file, line)) {
        std::vector<double> row;
        std::stringstream sstream(line);
        while (std::getline(sstream, value, ',')) {
            row.push_back(std::stod(value));
        }
        data.push_back(row);
    }

    file.close();
    return data;
}

// Custom logic to detect pulsar signal (Placeholder: frequency threshold detection)
bool detectPulsarSignal(const std::vector<double>& data) {
    // Simple threshold detection on the frequency spectrum
    double threshold = 10.0;  // Placeholder threshold for pulsar detection
    int count = 0;

    for (double value : data) {
        if (value > threshold) {
            count++;
        }
    }

    // If enough values cross the threshold, detect pulsar
    return count > (data.size() * 0.05);  // Placeholder Value: if more than 5% exceed the threshold
}