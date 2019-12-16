# base variable for fdf

CC = gcc
DBG_FLAG = -g
CFLAGS = -c #-Wall -Wextra -Werror
HEADER_H = -I ../inc/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H) #$(DBG_FLAG)

EXECUTABLE = fdf
