# MO2 C++ Plugin Skeleton

## Requirements

- A valid MO2 installation.
- Microsoft Visual C++ Build Tools, you can download them from the
  [Visual Studio download page](https://visualstudio.microsoft.com/downloads/) (bottom
  of the page, under "Tools for Visual Studio 2019")
  - You **do not** need Visual Studio 2019 for this, you can use
    any IDE you want, but if you want to use Visual Studio 2019, feel free
    to do so (CMake can generate a solution for you).
- CMake (>= 3.13), download from [the official website](https://cmake.org/download/).
- Qt, download from [the official website](https://www.qt.io/download).

## Setup

1. Clone the repository.
2. Run the following commands (from the root of the repository):

```bash
# - PATH_TO_MO2 should point to your MO2 installation (the root
#   folder containing the main executable)
# - PATH_TO_QT should point to a Qt installation appropriate for the MO2 version your
#   are target, e.g., 6.7.1 for MO2 2.5.2
cmake -B build .  "-DMO2_PATH=C:\Modding\MO2" "-DCMAKE_PREFIX_PATH=C:\Qt\6.7.1\msvc2019_64"

# build the project and install the plugin
cmake --build . --config RelWithDebInfo --target INSTALL
```

This will create `mo2_cpp_plugin.dll` and put it in your MO2 plugins folder.

## VS Code

### Extensions

Install the required extensions for VS Code: CMake, C/C++, etc.

### Building

With the CMake extension, you can build by running the `CMake: Build` command or
clicking on the build icon on the task bar.

### Debugging

Create the following `launch.json` file in the `.vscode` folder (replace `${MO2_PATH}`
with the path to your MO2 installation):

```json
// .vscode/launch.json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "MO2 Debug",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${MO2_PATH}/ModOrganizer.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${MO2_PATH}",
        }
    ]
}
```

If you want to automatically build before installing, create the following task in
`.vscode/tasks.json` and add `"preLaunchTask": "CMake: Build & Install"` to the launch
configuration above:

```json
// .vscode/tasks.json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "CMake: Build & Install",
            "type": "shell",
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "command": "cmake --build build --target INSTALL --config RelWithDebInfo"
        }
    ]
}
```
