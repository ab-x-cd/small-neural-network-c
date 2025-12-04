# Neural Network (C)

This repository is a small, educational implementation of a feed-forward neural network written in C. It includes basic matrix operations, a memory tracking helper (`memtrack`), and a minimal neural network implementation with ReLU activation in the forward pass. The network now supports training via backpropagation.

## Purpose

This project serves primarily educational purposes. It allows learning:
- The fundamental principles of artificial neural networks
- Implementation of matrix operations in C
- Memory management in C
- Using CMake for building C projects

It can also serve as a foundation for more advanced experiments with neural networks.

## Benefits

- **No external dependencies**: The project uses only the C standard library, making it easy to compile and run on any system with a C compiler.
- **Simple and readable code**: Ideal for understanding the internal mechanisms of neural networks without complex abstractions.
- **Integrated memory tracking**: The `memtrack` module allows monitoring memory usage, useful for debugging and optimization.
- **Included tests**: Simple test programs to verify matrix operations.
- **Cross-platform**: Works on Windows, Linux, and macOS.

## Prerequisites

- CMake (>= 3.10)
- A C compiler (GCC, Clang, MSVC depending on platform)
- (Optional) Ninja build tool for faster builds

## Building and Running

The project uses CMake as the build system. Below are platform-specific instructions.

### Linux

1. Open a terminal and navigate to the project directory.

2. Create a build directory and configure CMake:
   ```bash
   mkdir -p build
   cd build
   cmake .. -DCMAKE_BUILD_TYPE=Release
   ```

3. Build the project:
   ```bash
   cmake --build . --config Release
   ```

4. The executables `neural_network` and `test_matrix` will be created in the `build` directory.

### macOS

Steps are identical to Linux. You can install required tools using Homebrew:

```bash
brew install cmake
```

Then follow the same commands as Linux.

### Windows

#### With Visual Studio (recommended)

1. Open Command Prompt or PowerShell as administrator.

2. Create the build directory:
   ```cmd
   mkdir build
   cd build
   ```

3. Configure with CMake:
   ```cmd
   cmake .. -G "Visual Studio 17 2022" -A x64
   ```

4. Build:
   ```cmd
   cmake --build . --config Release
   ```

#### With Ninja

If you prefer Ninja:

1. Ensure Ninja is installed and in PATH.

2. Configure and build:
   ```cmd
   mkdir build
   cd build
   cmake .. -G Ninja
   cmake --build . --config Release
   ```

The executables `neural_network.exe` and `test_matrix.exe` will be created in `build\Release` (with Visual Studio) or `build` (with Ninja).

## Usage

After building, run the programs:

### Main Program (`neural_network`)

This program demonstrates creating and training a simple neural network on the XOR problem.

Run:
```bash
# Linux/macOS
./neural_network

# Windows
.\neural_network.exe
```

It will train the network and display test results.

### Matrix Tests (`test_matrix`)

This program tests matrix addition and multiplication.

Run:
```bash
# Linux/macOS
./test_matrix

# Windows
.\test_matrix.exe
```

It prints "PASSED" or "FAILED" for each test.

## Project Structure

- `include/`: Header files for matrix, memtrack, network.
- `src/`: Implementation files.
- `tests/`: Simple test programs (currently `test_matrix.c`).
- `CMakeLists.txt`: Project build configuration.

## Technical Notes

- The `memtrack` module wraps matrix allocations but the network uses standard `malloc`/`free`. For full tracking, adapt network allocations to use `mt_malloc`/`mt_free`.
- Matrix operations include basic dimension checks but do not handle errors robustly.
- The activation function is ReLU (Rectified Linear Unit).
- Weights are initialized with small random values.
- Backpropagation uses MSE loss and supports training on custom datasets.

## Contributing

Contributions are welcome. Open issues or PRs for bugs, features, or documentation. If adding features that change APIs, update headers and tests accordingly.

## License

No license file is included. Add an appropriate license if you wish to allow others to use/modify the code.

---

Small educational neural network C project.