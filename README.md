# MO2 C++ Plugin Skeleton

## Requirements

- Microsoft Visual C++ Build Tools, you can download them from the
  [Visual Studio download page](https://visualstudio.microsoft.com/downloads/) (bottom
  of the page, under "Tools for Visual Studio 2019")
  - You **do not** need Visual Studio 2019 for this, you can use
    any IDE you want, but if you want to use Visual Studio 2019, feel free
    to do so (CMake can generate a solution for you).
- CMake (>= 3.13), download from [the official website](https://cmake.org/download/).
- Qt 5.15.2, download from [the official website](https://www.qt.io/download).
- `uibase` headers and library.
  - **Note:** These are currently included in the `uibase` folder but might be
    removed in the future.

## Setup

1. Clone the repository.
2. Put the `uibase` headers (`.h`) and library (`.lib`) in the `uibase` subfolder
   if not already there.
3. Run the following commands (from the root of the repository):

```bash
# create a folder "build" and move to it
mkdir build && cd build

# PATH_TO_QT should point to your Qt installation, it usually ends
# in 5.15.2\msvc2019_64\ (for Qt5.15.2)
cmake .. -DCMAKE_PREFIX_PATH=${PATH_TO_QT}

# build the project
cmake --build . --target RelWithDebInfo
```

This will create `test-cpp-plugind.dll` under `build/src/RelWithDebInfo` in your folder,
you are now ready.
