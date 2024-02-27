# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andefern <andefern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 13:19:22 by andefern          #+#    #+#              #
#    Updated: 2024/02/27 10:17:23 by andefern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGAM NAME
NAME = so_long

# COMPILATON FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -g3 #-fsanitize=address
RM = /bin/rm -rf

# INCLUDE
INCLUDE = so_long.h

# LIBFT PATH
LIBFT = libft/
MLX = mlx/
#libA = libft/libft.a

# FILES TO COMPILE
SRC =	so_long.c \
		checks.c \
		counts.c \
		errors.c \
		flud_phill.c \
		inits.c \
		mlx_images.c \
		mlx_textures.c \
		mlx.c \
		movements_2.c \
		movements.c \
		p_locators.c \
		read_map.c
		

#OBJECTS (*.o)
OBJ = $(SRC:.c=.o)

# ASCII COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

# MAKEFILE ART #
define SO_LONG
$(PAPYRUS)

╔═╗╔═╗    ╦  ╔═╗╔╗╔╔═╗
╚═╗║ ║    ║  ║ ║║║║║ ╦
╚═╝╚═╝────╩═╝╚═╝╝╚╝╚═╝

$(END)
endef
export SO_LONG

#RULES
.SILENT:

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX) 2> /dev/null
	cp $(LIBFT)libft.a ./
	cp $(MLX)libmlx.a ./
	$(CC) -o $(NAME) $(OBJ) -Lmlx -framework OpenGL -framework AppKit libmlx.a libft.a
	echo "$$SO_LONG"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MLX) clean
	echo "objs deleted"

fclean: clean
	$(RM) $(NAME) libft.a libmlx.a
	echo "executable deleted"

re: fclean all

.PHONY: all clean fclean re