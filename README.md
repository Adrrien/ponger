# Ponger

A small C++ game project built with CMake.

## Project structure

- `src/` - source files
- `includes/` - project headers
- `CMakeLists.txt` - build configuration

## Install SFML

This project requires SFML 3.1.0. From the project root, clone SFML and check out its `3.1.0` tag:

```bash
git clone https://github.com/SFML/SFML.git build/SFML-src
cd build/SFML-src
git checkout 3.1.0
cd ../..
```

Configure SFML with CMake GUI or the command line. In CMake GUI, set the source directory to `build/SFML-src`, choose a separate build directory such as `build/SFML-build`, and set `CMAKE_INSTALL_PREFIX` to this project's `lib/SFML` directory. Then select **Configure** and **Generate**.

The equivalent command-line steps from the project root are:

```bash
cmake -S build/SFML-src -B build/SFML-build \\
	-DCMAKE_INSTALL_PREFIX="$PWD/lib/SFML"
cmake --build build/SFML-build
cmake --install build/SFML-build
```

`cmake --install` runs the install target (equivalent to `make install` with a Makefiles generator) and places SFML's headers, libraries, and CMake package files in `lib/SFML`.

## Build

From the project root:

```bash
cmake -S . -B build
cmake --build build
```

Then run the executable:

```bash
./build/ponger
```

## Notes

This project currently includes a minimal setup and can be extended with gameplay logic, assets, and additional modules as development continues.
