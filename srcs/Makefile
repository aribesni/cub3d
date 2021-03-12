# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 13:26:02 by aribesni          #+#    #+#              #
#    Updated: 2020/10/02 18:24:57 by aribesni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		Cub3D

OS = 		${shell uname}

SRCS = 		cub3d.c move.c def_world.c convert_endian.c image.c \
			key_events.c store_color.c main.c raycasting.c textures.c \
			create_map.c sprites.c init.c spawn.c free.c screenshot.c \
			check_path.c get_info.c add_sprite.c cub3d_utils.c \

CFLAG = 	-Wall -Wextra -Werror -I ${HEADER}

HEADER = cub.h

#CC = gcc

OBJS =		${SRCS:.c=.o}

ifeq ($(OS),Linux)
	MLX_LNK = -lm -lX11 -lXext
	MLX_DIR = ../minilibx/minilibx_linux/
	LIBS = libft/libft.a ../minilibx/minilibx_linux/libmlx.a
#	HEADER = cub.h libft/libft.h ../minilibx/minilibx_linux/mlx.h
	CC = clang
else
	MLX_LNK = -framework OPENGL -framework Appkit -lmlx -lft
	MLX_DIR = ../minilibx/minilibx_opengl_20191021/
	LIBS = libft/libft.a ../minilibx/minilibx_opengl_20191021/libmlx.a
#	HEADER = cub.h libft/libft.h ../minilibx/minilibx_opengl_20191021/mlx.h 
	CC = gcc
endif

L_DIR =		./libft/

all: 		libft minilibx ${NAME}

#${LIBS}:
#			make -C ${MLX_DIR}
#			make -C ${L_DIR}

#${NAME}:	${OBJS} ${LIBS}
#			${CC} ${CFLAG} -I ${HEADER} -o ${NAME} ${OBJS} ${MLX_LNK} ${LIBS}

#.c.o:
#			${CC} ${CFLAG} -c $< -o $@

minilibx:
			make -C ${MLX_DIR}

libft:
			make -C ${L_DIR}

${NAME}:	${OBJS}
			${CC} ${CFLAG} ${MLX_LNK} ${SRCS} -L${MLX_DIR} -L${L_DIR} -o ${NAME}

#all: 		${NAME}

clean:
			rm -f ${OBJS}
			make clean -C ${L_DIR}
			make clean -C ${MLX_DIR}

fclean: 	clean
			rm -f ${NAME}
			make fclean -C ${L_DIR}
			make clean -C ${MLX_DIR}

re: 		fclean all

.PHONY : 	all minilibx libft clean fclean re