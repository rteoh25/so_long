# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 16:15:04 by rteoh             #+#    #+#              #
#    Updated: 2024/08/21 18:41:59 by rteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlibx -lmlx
FRAMEWORKS = -framework OpenGL -framework AppKit
FSAN = -fsanitize=address
DEBUG = -g3
INCLUDES = ./includes
MLX = /usr/local/lib/libmlx.a
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

OBJ_DIR = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

SRC_DIR = src/
SRC = error.c render1.c exit.c render2.c free.c so_long.c hitbox.c \
    image_utils.c update_player.c images.c update_player_utils.c \
    init_entities_1.c utils.c init_entities_2.c validate_map.c \
    move.c validate_path.c move_player.c validate_path_utils.c \
    parse_map.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $(OBJS) ${MLX} ${LIBFT} $(PRINTF) $(LDFLAGS) $(FRAMEWORKS) -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

