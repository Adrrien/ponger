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

Configure SFML with CMake GUI or the command line. In CMake GUI, set the source directory to `build/SFML-src`, choose a separate build directory such as `build/SFML-build-old`, and set `CMAKE_INSTALL_PREFIX` to this project's `lib/SFML` directory. Then select **Configure** and **Generate**.

The equivalent command-line steps from the project root are:

```bash
cmake -S build/SFML-src -B build/SFML-build-old \\
	-DCMAKE_INSTALL_PREFIX="$PWD/lib/SFML"
cmake --build build/SFML-build-old --config Release
cmake --install build/SFML-build-old
```

On Windows PowerShell, use a single line or a backtick (`` ` ``) for
continuation; `\` does not continue a command in PowerShell:

```powershell
cmake -S build/SFML-src -B build/SFML-build -DCMAKE_INSTALL_PREFIX="$PWD\lib\SFML"
cmake --build build/SFML-build --config Release
cmake --install build/SFML-build --config Release
```

`cmake --install` runs the install target (equivalent to `make install` with a Makefiles generator) and places SFML's headers, libraries, and CMake package files in `lib/SFML`.

## Build

From the project root:

```bash
cmake -S . -B build/ponger-build -DCMAKE_PREFIX_PATH="$PWD/lib/SFML"
cmake --build build/ponger-build
```

Then run the executable:

```bash
./build/ponger
```

On Windows PowerShell, use:

```powershell
cmake -S . -B build\ponger-build -DCMAKE_PREFIX_PATH="$PWD\lib\SFML"
cmake --build build\ponger-build --config Release
.\build\ponger-build\Release\ponger.exe
```

## Gameplay

Use the left and right arrow keys to position the ball, then hold
**Space** to charge and release it to launch. The green gauge at the top
left shows the current launch power. Put the ball in the red cup to win the
round: the score increases, the window title shows the win, and the ball
returns to its starting position.

## Notes

This project currently includes a minimal setup and can be extended with gameplay logic, assets, and additional modules as development continues.
