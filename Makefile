# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 15:05:59 by ncruz-ga          #+#    #+#              #
#    Updated: 2023/11/08 11:31:36 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

MLX_PATH = ./MLX42

MLX = $(MLX_PATH)/libmlx42.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

SO_LONG = so_long.a

SO_LONG_BONUS = so_long_bonus.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs

LIB_SYS = -Iinclude -lglfw -L "/Users/ncruz-ga/.brew/opt/glfw/lib/"

RM = rm -f

SRC = src/so_long.c src/read_map.c src/check_map.c src/valid_way.c src/image.c src/player.c src/resize.c

SRC_BONUS = srcb/so_long_bonus.c srcb/read_map_bonus.c srcb/check_map_bonus.c srcb/valid_way_bonus.c srcb/image_bonus.c srcb/player_bonus.c srcb/resize_bonus.c srcb/mob_bonus.c srcb/clean_texture_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
				@$(LIB) $(SO_LONG) $(OBJ)
				@$(CC) $(CFLAGS) $(SO_LONG) $(MLX) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(OBJ):		src/%.o : src/%.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS):	$(OBJ_BONUS) $(LIBFT) $(MLX)
				@$(LIB) $(SO_LONG_BONUS) $(OBJ_BONUS)
				@$(CC) $(CFLAGS) $(SO_LONG_BONUS) $(MLX) $(LIBFT) $(LIB_SYS) -o $(NAME_BONUS)

$(OBJ_BONUS):	srcb/%.o : srcb/%.c
				$(CC) $(CFLAGS) -c $< -o $@
				
$(LIBFT):
					@make -s -C $(LIBFT_PATH)

$(MLX):
					@make -s -C $(MLX_PATH)

all:		$(NAME)

bonus:		$(NAME_BONUS)

clean:
					$(RM) $(OBJ) $(OBJ_BONUS)
					make clean -s -C $(MLX_PATH)
					make clean -s -C $(LIBFT_PATH)

fclean:
					$(RM) $(NAME) $(NAME_BONUS) $(OBJ) $(OBJ_BONUS) $(SO_LONG) $(SO_LONG_BONUS) $(LIBFT) $(MLX)
					make fclean -s -C $(MLX_PATH)
					make fclean -s -C $(LIBFT_PATH)

re:			fclean all

solong:		all clean

.PHONY: all re clean fclean solong bonus solongb