# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 15:24:20 by kwpark            #+#    #+#              #
#    Updated: 2022/11/17 11:33:02 by kwpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

MLX = minilibx

SOURCES = 	src/get_berfile.c \
			src/key_press.c \
			src/so_long.c \
			src/error_check.c \
			src/so_long_utils.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@cp libft/libft.a ./
	@cp minilibx/libmlx.a ./
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) libft.a libmlx.a

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS) libft.a libmlx.a
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)

re: fclean all

.PHONY : all, clean, fclean, re, bonus