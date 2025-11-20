<div align="center">

# 🌀 FRACTALS — Infinite Fractal Generator & Explorer

**An interactive infinite fractal generator built in C, supporting Mandelbrot, Julia, and Burningship sets with smooth zoom, color cycling, and live parameter control.**

A 42 School **fract-ol** project

![License](https://img.shields.io/badge/license-MIT-green.svg)
![Language](https://img.shields.io/badge/language-C-blue.svg)
![42Project](https://img.shields.io/badge/42-school-black.svg)

</div>

## 🌟 Overview

**fract-ol** is an interactive fractal generator and infinite-zoom explorer.  
It renders the mathematical sets of **Mandelbrot**, **Julia**, and **Burningship** in real time using **MiniLibX**, allowing users to zoom, move, modify parameters, and apply color palettes.

Although fractals are mathematically infinitely detailed, the maximum zoom depth ultimately depends on floating-point precision and the performance of your computer.
This implementation uses **long double** for extended precision. In the bonus version, pressing `+` increases the iteration depth by 500, allowing significantly deeper exploration.

<p align="center">
    <img src="screenshots/MandelbrotRed.png" width="50%">
    <img src="screenshots/Mandelbrot.png" width="50%">
</p>

---

## 🎮 Features

### Mandatory Features

- **Mandelbrot Set**
- **Julia Set**
- Smooth zoom with mouse wheel
- Multiple Julia sets by changing parameters
- Smooth window management and clean exit (ESC / close window)
- Multi-color palettes to reveal fractal depth
- Uses MiniLibX images for rendering

### Bonus Features

<p align="center">
  <img src="screenshots/BurningShip.png" width="25%">
  <img src="screenshots/BurningShip2.png" width="25%">
  <img src="screenshots/Julia.png" width="25%">
  <img src="screenshots/JuliaBlue.png" width="25%">
</p>

- Additional fractal (Burningship)
- Zoom follows mouse position
- Panning using arrow keys
- Color cycling and gradient shifts
- Dynamic Julia parameters updated by mouse movement
- Adjustable iteration depth for deeper exploration
- Support for custom window size *(100×100 → 800×800)* 

---

## 🙌 Credits 

**MiniLibX** — graphical library provided by 42 School for window creation, event handling, and pixel rendering. 

---

## 🚀 Installation & Usage

### 0️⃣ Download MiniLibX

MiniLibX is not included in this repository to avoid duplicating it across multiple projects.
Download it from my cub3D repo:

https://github.com/YLZHUANG/cub3D/tree/main/mlx

### 1️⃣ Clone the repository

``` bash
git clone git@github.com:YLZHUANG/fract-ol.git fractals
cd fractals
```
Place MiniLibX at the root of the project.

### 2️⃣ Build

Mandatory version:

``` bash
make
```

Bonus version:

``` bash
make bonus
```

After make, you may see informational messages or warnings from MiniLibX in the terminal. These are not errors in my code — they usually come from the library itself (e.g. build logs, X11 details). If your build succeeds, you can safely continue and run the program.

### 3️⃣ Run

Mandatory version:

``` bash
➜ ./fractol

MENU : FRACTALS       OPTIONS
M    : Mandelbrot     W{100, 800} H{100, 800}
J    : Julia          {double} {double} W{100, 800} H{100, 800}
B    : Burningship    W{100, 800} H{100, 800}

➜ ./fractol M // for mandelbrot
```

Bonus version:

```bash
➜ ./bonus

MENU : FRACTALS       OPTIONS
M    : Mandelbrot     W{100, 800} H{100, 800}
J    : Julia          {double} {double} W{100, 800} H{100, 800}
B    : Burningship    W{100, 800} H{100, 800}

➜ ./bonus M
````

### 4️⃣ Enjoy

| Action (Bonus)                        | Key / Input                      |
| ------------------------------------- | -------------------------------- |
| Zoom in/out                           | Mouse wheel                      |
| Move view                             | Arrow keys                       |
| Change color gradient                 | `C`                              |
| Exit                                  | `ESC` or close window            |
| Adjust iteration depth (+/- 500)      | `+` / `-`                        |
| Change Julia interactively (support red mode only) | Pressing left mouse button, and move |

---

# 🧾 Notes

**For learning purposes :** This project represents my exploration of transforming mathematical formulas into interactive, infinitely evolving visuals. 
The code isn’t perfect, but it’s clean and doesn’t leak memory.