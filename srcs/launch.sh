#!bin/bash

make clean -C ../minilibx/minilibx_opengl_20191021

make fclean -C ./libft/

make -C ../minilibx/minilibx_opengl_20191021

make -C ./libft/

gcc -Wall -Wextra -Werror -framework OPENGL -framework Appkit *.c ../minilibx/minilibx_opengl_20191021/libmlx.a ./libft/libft.a -o Cub3D && ./Cub3D ./map/map_test.cub
