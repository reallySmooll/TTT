# TTT
TTT is a simple wrapper library around SFML made to simplify the making of an SFML game.

## Building
**NOTE: To build on Windows or macOS, you will need to check the meson documentation by yourself. Maybe I'll consider doing that but that's a project for another day.**

### Dependencies
Like with any project, there will always be some dependencies (no exceptions), this project has them:

- SFML (the library that's being wrapped)
- Meson (the build system)
- Ninja
- git
- A C++ compiler
- pkg-conf

### Actually building
4 commands, not much else if you have all of the needed dependencies.

```bash
$ git clone https://github.com/reallySmooll/TTT.git
$ cd TTT
$ meson setup build
$ meson compile -C build
```

You can also do:

```bash
$ sudo meson install -C build
$ sudo mv /usr/local/lib/pkgconfig/TTT.pc /usr/lib/pkgconfig/
```

The latter commands will install the library system-wide so you can use it anywhere without having to keep a `.a` file in your `lib` folder.

## Usage
A basic setup looks something like this (main.cpp):

```cpp
#include <TTT/TTT.hpp>

#include <string>

constexpr int WINDOW_WIDTH         = 800;  // You don't have to write it exactly like here.
constexpr int WINDOW_HEIGHT        = 600;  // You don't have to write it exactly like here.
constexpr std::string WINDOW_TITLE = "TTT" // You don't have to write it exactly like here.

int main()
{
    TTT::Window::verbose                      = true; // True or false for debug output.
    TTT::Window::toggleFPS                    = true; // True or false for toggling FPS at startup.
    TTT::Window::shouldCreateDefaultEventLoop = true; // True or false for creating a default immutable event loop.

    TTT::Window ttt(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE /* optional */);

    return 0;
}
```

## Documentation
Documentation is work in progress but you can already find it at https://reallysmooll.github.io/TTT-docs.
