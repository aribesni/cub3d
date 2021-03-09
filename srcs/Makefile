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

HEADER = 	cub3d.h

CFLAG = 	-Wall -Wextra -Werror -I${HEADER}

CC = 		gcc

OBJS =		${SRCS:.c=.o}

MLX_LNK =	-framework OPENGL -framework Appkit -lmlx -lft

MLX_DIR = 	../minilibx/minilibx_opengl_20191021/

L_DIR =		./libft/

all: 		libft minilibx ${NAME}

minilibx:
			make -C ${MLX_DIR}

libft:
			make -C ${L_DIR}


${NAME}:	${OBJS}
			${CC} ${CFLAG} ${MLX_LNK} ${SRCS} -L${MLX_DIR} -L${L_DIR} -o ${NAME}

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