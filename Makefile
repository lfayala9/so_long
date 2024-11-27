# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layala-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 14:49:46 by layala-s          #+#    #+#              #
#    Updated: 2024/10/27 14:49:48 by layala-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Wextra -Werror 

OBJS = $(SRCS:.c=.o)

SRCS = ./srcs/get_map.c \
	   ./srcs/validate_map.c \
	   ./srcs/validate_utils.c \
	   ./srcs/utils.c \

INCLUDES = -I include ./libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS)
			@make -C libft
			@make -C minilibx-linux
			@gcc main.c $(SRCS) $(INCLUDES) -o $(NAME)

clean:
		@make clean -C libft
		@make clean -C minilibx-linux
		rm -rf $(OBJS)

fclean:
		@make fclean -C libft
		@make clean -C minilibx-linux
		@rm -rf $(OBJS)
		@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean