#!bin/bash

make -C ../minilibx/minilibx_opengl_20191021

gcc -Wall -Wextra -Werror -framework OPENGL -framework Appkit ../minilibx/minilibx_opengl_20191021/libmlx.a *.c -o Cub3D && ./Cub3D
