# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribesni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 14:40:03 by aribesni          #+#    #+#              #
#    Updated: 2020/07/01 15:24:10 by aribesni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_memchr.c ft_strdup.c ft_bzero.c ft_memcmp.c ft_strequ.c \
ft_calloc.c ft_memcpy.c ft_strjoin.c ft_isalnum.c ft_memmove.c ft_strlcat.c \
ft_isalpha.c ft_memset.c ft_strlcpy.c ft_isascii.c ft_putchar.c ft_strlen.c \
ft_isdigit.c ft_putchar_fd.c ft_strmapi.c ft_isprint.c ft_putendl.c \
ft_strncat.c ft_itoa.c ft_putendl_fd.c ft_strncmp.c ft_putnbr.c ft_strncpy.c \
ft_putnbr_fd.c ft_strnequ.c ft_putstr.c ft_strnew.c ft_putstr_fd.c \
ft_strnstr.c ft_split.c ft_strrchr.c ft_strcat.c ft_strstr.c ft_strchr.c \
ft_strtrim.c ft_strclr.c ft_substr.c ft_strcmp.c ft_tolower.c ft_memccpy.c \
ft_strcpy.c ft_toupper.c ft_printf.c ft_print_c.c ft_print_s.c ft_putnbr_base.c \
ft_print_i_u.c ft_print_p.c ft_assign.c ft_display.c ft_dot_s.c ft_rest.c \
ft_ret.c ft_wildcard.c ft_zero.c ft_printf_utils.c get_next_line.c ft_putnbr_base_u.c \
ft_uitoa_base.c \

SRCS_BONUS = ft_lstadd_back.c ft_lstadd_front.c \
 ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
 ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libft.a

BONUS = bonus

HEADER = ./libft.h

all : ${NAME}

clean :
	    ${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	    ${RM} ${NAME}

$(NAME) : ${OBJS}
	    ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

$(BONUS) : ${OBJS} ${OBJS_BONUS}
		ar rc ${NAME} ${OBJS} ${OBJS_BONUS}
		ranlib ${NAME}

re : fclean all

.PHONY : all clean fclean re
