# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 15:49:50 by fmasha-h          #+#    #+#              #
#    Updated: 2019/10/01 15:47:43 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = fdf.h

GCC = gcc -Wall -Wextra -Werror -g

# school macOS
# MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit
# home macOS
MLX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

MAKE_LIB = make -C libft

LIBFT = libft/libft.a

DIR_SRCS = srcs

DIR_O = obj

SRCS = 	main.c \
		init.c \
		bresenham_alg.c \
		input_processing.c \
		validation.c \
		centering.c \
		isometry.c \
		rotation.c \
		color.c \
		keys.c

OBJF = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SRCS)))

all: $(MAKE_LIB) $(NAME)

$(MAKE_LIB):
	@make -C libft

$(DIR_O):
	@mkdir -p obj

$(NAME): $(DIR_O) $(OBJF) $(LIBFT)
	$(GCC) -I $(HEADER) $(OBJF) $(LIBFT) $(MLX) -o $(NAME)

$(DIR_O)/%.o: $(DIR_SRCS)/%.c 
	$(GCC) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all