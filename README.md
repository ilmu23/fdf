# FdF

![42.fdf](https://github.com/ilmu23/fdf/raw/master/img/42.png)

## Overview

FdF is a program for drawing wireframe models.

## Compilation

### Linux

0. Install minilibx dependencies
    - xorg
    - x11
    - zlib
1. Clone the repository and run make
    ```bash
    git clone https://github.com/ilmu23/fdf.git
    cd fdf
    make
    ```

### MacOS

0. Install minilibx
1. Clone the repository and run make
    ```bash
    git clone https://github.com/ilmu23/fdf.git
    cd fdf
    make
    ```

### Windows

**no**

### Make options

Instead of building with the default BUILD (fast) you can 
specify a different build target when running make

```bash
make BUILD=debug
```

The available build targets are

BUILD   | CFLAGS                        | Effect
| :---: | :---:                         | :---:
normal  | -Wall -Wextra -Werror         | None
fast    | normal + -Ofast               | Compiler optimizations
debug   | normal + -g                   | Debug symbols
debugm  | debug + -D DEBUG_MSG=1        | Debug symbols + messages
asan    | debug + -fsanitize=address    | Address sanitizer

## Usage

Launch the executable with a path to an fdf map as
its only argument

```bash
./fdf maps/42.fdf
```

ACTION                                      | KEYBIND
| :---:                                     | :---:
Clockwise rotation                          | E
Counter-clockwise rotation                  | Q
Translate up                                | W
Translate down                              | S
Translate right                             | D
Translate left                              | A
Zoom in                                     | X
Zoom out                                    | Z
Toggle automatic rotation                   | R
Toggle drawing flat color only at height 0  | F
Quit                                        | Q

## Known ~~Issues~~ Features

Sometimes the translate keys are flipped. I have no idea
what causes that shit, but I'll just pretend like its
a feature.
