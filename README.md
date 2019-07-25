# Fractol_1337

Fract'ol @ [1337](https://www.1337.ma/) (One of the [42](https://www.42.fr/) Network Schools) - multi-threaded fractal renderer

![screenshot](/screens/screen.png?raw=true)

## Features

* Render different fractals: mandelbrot, julia, burning ship ...etc.
* Different gradient color schemes.
* Smooth and linear coloring.
* Multi-threaded.

## Compiling and running

What things you need to install the software and run it to your mac.

```
git clone https://github.com/Imgox/Fractol_1337 && cd Fractol_1337
make fractol
```
after making and building the software, here's how your run it.

```
╔══════════════════════════════════════════╗
║       Usage: ./fractol <fractal>         ║
╚══════════════════════════════════════════╝
           ╔════════════════════╗           
╔══════════╣ Available fractals ╠══════════╗
║          ╚════════════════════╝          ║
║                                          ║
║                mandelbrot                ║
║                  julia                   ║
║               burning_ship               ║
║                 tricorn                  ║
║             cubic_mandelbrot             ║
║             fourth_mandelbrot            ║
║              cubic_mandelbar             ║
║             fourth_mandelbar             ║
║                                          ║
╚══════════════════════════════════════════╝
```

### User Interface:

| Feature | Keys |
| --- | --- |
| Move | Arrows |
| Zoom | Mouse Wheel |
| Change Colorscheme | C |
| Next Fractal | N |
| Reset Limits | R |
| Increase iterations | + |
| Decrease iterations | - |
| Stop the movement (in Julia Set) | M |
| Exit | ESC |


## Built With

* C Standard
* [MLX](https://github.com/ttshivhula/minilibx) - Mini Graphic Library


## Authors

* **Souhaib LAANANI** - *Initial work* - [Imgox](https://github.com/Imgox)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
 
