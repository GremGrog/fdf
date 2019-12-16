# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 09:46:55 by yquaro            #+#    #+#              #
#    Updated: 2019/12/16 10:34:03 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../inc/fdf.mk

PATH_TO_MAIN = ../src
LIBNAME = ../libft/libft.a
OBJS = *.o
MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

CFLAGS = -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) $(HEADER_H) #$(DBG_FLAG)

all:
	$(COMPILING) $(PATH_TO_MAIN)/main.c $(OBJS) $(LIBNAME) $(MLX) -o ../$(EXECUTABLE)

clean:
	@rm -rf $(OBJS)

fclean:
	@rm -rf ../$(EXECUTABLE)
