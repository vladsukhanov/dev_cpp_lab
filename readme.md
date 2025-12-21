# dev_cpp_lab

This is a simple C++ template project.
The project uses **CMake** to manage the build process.

## Requirements

 * **CMake** (minimum version 3.10)
 * **MinGW** or **MSYS2** to use Makefiles on Windows, or any other supported C++ compilation environment.

## Building the Project

### 1. Preparation

 * Ensure you have **CMake** and a C++ compiler installed.
 * To build with Makefiles on Windows, it is recommended to install **MinGW** or **MSYS2**.

### 2. Building with CMake

1. Navigate to the project's root directory.

2. Create a build directory: `mkdir build` than `cd build`

3. Run CMake, specifying the generator: `cmake -G "Unix Makefiles" ..`

4. Build the project: `make` or `cmake --build .`

5. Run the program: `./sample_program.exe`

### 3. Cleaning the Project

To clean the project and remove generated files, execute the following command:

To delete all files:
 * `cd build`
 * `del /Q *.*`

To delete all subdirectories and files:
 * `cd build`
 * `rmdir /S /Q .`

Or using PowerShell: `Remove-Item * -recurse -force`

## Doxygen
1. Create a Doxyfile
2. Add the project name to `PROJECT_NAME`
3. Add the output directory to `OUTPUT_DIRECTORY`
4. Disable the `GENERATE_LATEX` option (`GENERATE_LATEX = NO`)
5. Run doxygen: `doxygen .\Doxyfile`

## Tests & Coverage

### Running Tests

1. Navigate to the build directory: `cd build`

2. Run the tests using CTest: `ctest --output-on-failure`

### Checking Code Coverage

1. Build the project with coverage support (the `-fprofile-arcs -ftest-coverage` flags are already added in `CMakeLists.txt`).

2. After running the tests, execute the command to generate a coverage report:
 * For lcov (using MSYS2):
   * `cd /.../coverage_lcov`
   * `lcov --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1`
   * `genhtml coverage.info --output-directory coverage_report`

 * For gcovr:
   * `cd coverage_gcovr`
   * `gcovr ../build -v -r ../source --html --html-details -o coverage.html`

3. Open the `coverage_report/index.html` file to view the coverage report in your browser.

**Note:** To use code coverage, use the GCC/MinGW compiler. Coverage is not supported with MSVC.
