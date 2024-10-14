#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

// Function to read CSV file and return data as a 2D vector
std::vector<std::vector<double>> readCSV(const std::string& filename);

// Function to detect pulsar signal (custom logic)
bool detectPulsarSignal(const std::vector<double>& data);

#endif