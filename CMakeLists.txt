# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(PulsarDetection VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add executable and source files
add_executable(pulsar_detection
    src/main.cpp
    src/fft.cpp
    src/wavelet.cpp
    src/denoising.cpp
    src/utils.cpp
)

# Add any necessary libraries (e.g., FFTW or others)
# For example, if using FFTW
# find_package(FFTW REQUIRED)
# target_link_libraries(pulsar_detection FFTW::FFTW)

# Optionally, set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include external libraries (if needed)
# Include FFTW, etc.
# include_directories(${FFTW_INCLUDE_DIRS})

# If linking libraries, for example:
# target_link_libraries(pulsar_detection ${FFTW_LIBRARIES})
