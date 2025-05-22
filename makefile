# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 19:46:51 by alejagom          #+#    #+#              #
#    Updated: 2025/05/21 21:24:38 by alejogogi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.c) 
OBJ = $(SRC:.c=.o)

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

LIB_DIR = ./libft
LIBFT =	$(LIB_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

INCLUDE = include/so_long.h
MLX_IINCLUDE = minilibx-linux
LIBFT_INCLUDE = libft
FT_PRINTF_INCLUDE = ft_printf

RM = rm -f

.PHONY: all clean fclean re

all: $(MLX) $(LIBFT) $(FT_PRINTF) $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)
	
$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)
	
	@clear
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean: 
	$(RM) $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean:
	$(RM) $(OBJ) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all
