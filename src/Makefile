# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 09:46:47 by yquaro            #+#    #+#              #
#    Updated: 2019/12/16 16:24:33 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../inc/fdf.mk

HEADER_H = -I ../inc/

DIR_O = ../obj
SOURCES = mlx_initialization.c map_parsing.c calculate_coords.c connect_lines.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling src

$(DIR_O)/%.o: %.c
	@$(COMPILING) $< -o $@
	@echo "Compile " $(notdir $(@:.o=.c))

clean: 
	@rm -rf $(OBJECTS)

fclean: clean
