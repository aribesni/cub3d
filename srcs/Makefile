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

NAME = Cub3D

SRCS = cub3d.c ft_move.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MLXDIR = ../minilibx/minilibx_opengl_20191021/

MLX_LNK = -lmlx -framework OPENGL -framework Appkit -Llibft -lft

all : minilibx ${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

minilibx:
			@make -C ${MLXDIR}

$(NAME) : ${OBJS} minilibx
			ar rc ${NAME} ${OBJS} ${MLX_LNK}

clean :
		${RM} ${OBJS}
		@make -C ${MLXDIR} clean

fclean : clean
			${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
