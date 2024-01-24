# FdF

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
------- | ----------------------------- | ------------------------
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
