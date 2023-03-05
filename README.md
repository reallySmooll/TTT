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

```
$ git clone https://github.com/reallySmooll/TTT.git
$ cd TTT
$ meson setup build
$ meson compile -C build
```

You can also do:

```
$ sudo meson install -C build
$ sudo mv /usr/local/lib/pkgconfig/TTT.pc /usr/lib/pkgconfig/
```

The latter commands will install the library system-wide so you can use it anywhere without having to keep a `.a` file in your `lib` folder.

## Documentation
The documentation is a work in progress so please be patient.
