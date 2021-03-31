# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 13:26:02 by aribesni          #+#    #+#              #
#    Updated: 2021/03/28 15:02:17 by aribesni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		Cub3D

OS = 		${shell uname}

SRC = 		add_sprite.c create_map.c cub3d.c cub3d_utils.c \
			cub3d_utils_2.c def_world.c free.c free_2.c get_info.c image.c \
			main.c move.c raycasting.c screenshot.c sprites.c store_color.c \

SRCS = 		$(addprefix ./srcs/, $(SRC))

#CFLAG = 	-Wall -Wextra -Werror -I ${HEADER}

CFLAG = 	-Wall -Wextra -Werror

#HEADER = includes/cub.h

OBJS =		${SRCS:.c=.o}

ifeq ($(OS),Linux)
	MLX_LNK = -lm -lX11 -lXext
	MLX_DIR = minilibx/minilibx_linux/
	LIBS = libft/libft.a minilibx/minilibx_linux/libmlx.a
	CC = clang
else
	MLX_LNK = -framework OPENGL -framework Appkit -lmlx -lft
	MLX_DIR = minilibx/minilibx_opengl_20191021/
	LIBS = libft/libft.a minilibx/minilibx_opengl_20191021/libmlx.a
	CC = gcc
endif

all: 		${NAME}

L_DIR =		./libft/

#all: 		libft minilibx ${NAME}

${LIBS}:
			make -C ${MLX_DIR}
			make -C ${L_DIR}

${NAME}:	${OBJS} ${LIBS}
			${CC} ${CFLAG} -o ${NAME} ${OBJS} ${MLX_LNK} ${LIBS}

.c.o:
			${CC} ${CFLAG} -I ./includes/ -c $< -o $@

#minilibx:
#			make -C ${MLX_DIR}

#libft:
#			make -C ${L_DIR}

#${NAME}:	${OBJS}
#			${CC} ${CFLAG} ${MLX_LNK} ${SRCS} -L${MLX_DIR} -L${L_DIR} -o ${NAME}

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
