# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 15:24:20 by kwpark            #+#    #+#              #
#    Updated: 2022/10/31 17:49:39 by kwpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

MLX = minilibx

SOURCES = 	test_img.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@cp libft/libft.a ./
	@cp minilibx/libmlx.dylib ./
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a libmlx.dylib

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS) libft.a libmlx.dylib
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)

re: fclean all

.PHONY : all, clean, fclean, re, bonus