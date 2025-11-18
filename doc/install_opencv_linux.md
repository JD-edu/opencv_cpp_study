# 🤖 OpenCV C++ Installation Guide for Linux (Building from Source)

Building OpenCV from source is the preferred method for C++ development on Linux, as it ensures all system dependencies are correctly linked and allows for advanced features (like CUDA or specialized modules) to be enabled.

This guide assumes you are using a Debian/Ubuntu-based distribution.

## Phase 1: Preparation and Prerequisites

First, ensure your system has the essential development tools, the CMake build system, and all required library dependencies.

### 1.1 Install Build Tools and CMake

The core requirements include a C++ compiler (g++), make, git, and cmake.
```
# Update package list
sudo apt update

# Install essential tools: C++ compiler, CMake, Git, and pkg-config
sudo apt install -y build-essential cmake git pkg-config
```

### 1.2 Install Media & GUI Dependencies

Install libraries required for reading image and video files, and for displaying windows (required for functions like cv::imshow).
```
# Image I/O libraries (JPEG, PNG, TIFF)
sudo apt install -y libjpeg-dev libpng-dev libtiff-dev
# Video I/O libraries (FFmpeg)
sudo apt install -y libavcodec-dev libavformat-dev libswscale-dev
# GUI backend (GTK3 for displaying windows)
sudo apt install -y libgtk-3-dev
```

## Phase 2: Download and Configure the Source

We will download the source code for the main library and the extra/contributed modules, then use CMake to configure the build environment.

### 2.1 Clone the Repositories

Create a working directory and clone the official OpenCV and opencv_contrib repositories.
```
# Create and enter the working directory
mkdir ~/opencv_build
cd ~/opencv_build
# Clone the main OpenCV repository
git clone [https://github.com/opencv/opencv.git](https://github.com/opencv/opencv.git)
# Clone the extra modules (optional, but highly recommended)
git clone [https://github.com/opencv/opencv_contrib.git](https://github.com/opencv/opencv_contrib.git)
```

### 2.2 Configure with CMake

Create a separate build directory for the compiler output, then run the cmake command.
```
cd opencv
mkdir build
cd build
# Configure the build using CMake
# CMAKE_BUILD_TYPE=Release: Enables compiler optimizations for speed.
# CMAKE_INSTALL_PREFIX=/usr/local: Installs files to the standard system location.
# OPENCV_EXTRA_MODULES_PATH: Links the contrib modules.
cmake -D CMAKE_BUILD_TYPE=Release \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
      .. 
```

## Phase 3: Build, Install, and Verify

### 3.1 Compile the Source Code

This step takes the longest. Use the -j flag followed by the number of CPU cores you want to use to accelerate the compilation process (e.g., -j4 for 4 cores).
```
# Compile the source code (Change '8' to your desired core count)
make -j8
```

### 3.2 Install and Update Cache

After compilation is complete, install the headers and libraries into the system directories.
```
# Install OpenCV to the system directories (requires root privileges)
sudo make install
# Update the dynamic linker run-time bindings cache
sudo ldconfig
```

The headers will now be located in a path like /usr/local/include/opencv4/.

## Phase 4: Compiling Your C++ Project

If you use the manual command, here is the form. Crucially, ensure your C++ file uses forward slashes in the include statement.

In 101_read_image.cpp:
```
// Correct way to include in Linux/POSIX systems
#include <opencv2/opencv.hpp>
// Also ensure your main function is correct:
int main(int argc, char** argv) {
    // ...
    return 0;
}
```


Compilation Command:
```
g++ 101_read_image.cpp -o 101_read_image -I/usr/local/include/opencv4 -L/usr/local/lib -lopencv_core -lopencv_videoio -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

```
