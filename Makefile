# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 02:28:29 by rteoh             #+#    #+#              #
#    Updated: 2024/06/27 01:06:17 by rteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = cc
CFLAGS =-fsanitize=address -g3
LDFLAGS = -Lmlibx -lmlx
FRAMEWORKS = -framework OpenGL -framework AppKit
INCLUDES = ./includes


OBJ_DIR = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

SRC_DIR = src/
SRC = so_long.c error.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	${MAKE} -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./mlibx/libmlx.a ./libft/libft.a $(LDFLAGS) $(FRAMEWORKS) -o $(NAME)

clean:
	${MAKE} -C ./libft fclean
	rm -rf $(OBJ_DIR) $(NAME)

re: clean all
