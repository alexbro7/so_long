# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:58:48 by mahautlat         #+#    #+#              #
#    Updated: 2021/10/20 20:19:42 by alebross         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/free_map.c \
		srcs/ft_error.c \
		srcs/ft_strlen.c \
		srcs/get_map.c \
		srcs/get_next_line.c \
		srcs/get_sizemap.c \
		srcs/main.c \
		srcs/printmap.c \
		srcs/check_mapchar.c \
		srcs/check_wallaround.c \
		srcs/free_all.c \
		srcs/load_texture.c \
		srcs/print_map_to_win.c \
		srcs/deal_key.c \
		srcs/refresh.c \
		srcs/ft_putnbr.c \
		srcs/ft_strcpy.c \

OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)

PATH_MLX	= mlx
CC 			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re
