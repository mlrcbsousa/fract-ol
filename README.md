# fract-ol

42 school fract'ol project

## How to Install Minilibx on a Mac

The dependencies should already be installed by default.

Download Minilibx **OpenGL** tgz file from the project page and extract it.

```bash
cd /path/to/mlx
make
```

Download the man files from the linux git repo below.

**TODO:** Add instructions for setting up manual

Copy files to `/usr/` path

```bash
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/
```

After that, to compile your project:

```bash
gcc -Wall -Wextra -Werror main.c -lm -lmlx -framework OpenGL -framework AppKit
```

## How to Install Minilibx on Linux

Install dependencies

```bash
sudo apt-get install libxext-dev
sudo apt-get install libxrandr-dev
sudo apt-get install libx11-dev
sudo apt-get install libbsd-dev
sudo apt-get install libssl-dev
```

Download and configure library

```bash
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
```

Create manual directory

```bash
cd /usr/local/man/
sudo mkdir man1
```

Return to the minilibx directory

```bash
cd /path/to/minilibx-linux
```

Copy files to `/usr/` path

```bash
sudo cp man/man1/* /usr/local/man/man1/
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/
```

Test it, the following command must show the minilibx manual

```bash
man mlx
```

After that, to compile your project:

```bash
gcc -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11
```

[Rule of Thumb: On a linking command line, libraries go after object files, not before them.](https://stackoverflow.com/questions/59287273/how-do-i-compile-using-minilibx)
