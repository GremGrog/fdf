# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 15:49:50 by fmasha-h          #+#    #+#              #
#    Updated: 2019/09/24 14:47:11 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = fdf.h

GCC = gcc -Wall -Wextra -Werror -g

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

MAKE_LIB = make -C libft

LIBFT = libft/libft.a

DIR_SRCS = srcs

DIR_O = obj

SRCS = 	main.c \
		init_new_img.c \
		bresenham_alg.c \
		input_processing.c \
		validation.c \

OBJF = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SRCS)))

all: $(MAKE_LIB) $(NAME)

$(MAKE_LIB):
	@make -C libft

$(DIR_O):
	@mkdir -p obj

$(NAME): $(DIR_O) $(OBJF) $(LIB)
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