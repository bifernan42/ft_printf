# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bifernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:13:33 by bifernan          #+#    #+#              #
#    Updated: 2024/01/15 16:08:53 by bifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc -c
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
SRCS = ft_atoi.c \
	ft_directive_handler.c \
	ft_prct_count.c \
	ft_handlermanager.c \
	ft_managerwhile.c \
	ft_deallocate.c \
	ft_miniputhex.c \
	ft_structsetter.c \
	ft_setstruct_prct.c \
	ft_is_plusf.c \
	ft_isfcode.c \
	ft_itoa.c \
	ft_putchar2.c \
	ft_putstr2.c \
	ft_specifier_handler.c \
	ft_whilepercent.c \
	ft_convertbase.c \
	ft_is_hashtagf.c \
	ft_is_spacef.c \
	ft_isflag.c \
	ft_printf.c \
	ft_puthex.c \
	ft_putunsigned_nbr.c \
	ft_split.c \
	ft_directive_extractor.c \
	ft_is_minusf.c \
	ft_is_zerof.c \
	ft_ispercent.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_setdirectives.c \
	ft_strlen.c	
OBJ = ft_atoi.o \
	ft_directive_handler.o \
	ft_deallocate.o \
	ft_structsetter.o \
	ft_handlermanager.o \
	ft_setstruct_prct.o \
	ft_managerwhile.o \
	ft_miniputhex.o \
	ft_is_plusf.o \
	ft_whilepercent.o \
	ft_isfcode.o \
	ft_itoa.o \
	ft_putchar2.o \
	ft_putstr2.o \
	ft_specifier_handler.o \
	ft_convertbase.o \
	ft_is_hashtagf.o \
	ft_is_spacef.o \
	ft_isflag.o \
	ft_printf.o \
	ft_puthex.o \
	ft_putunsigned_nbr.o \
	ft_split.o \
	ft_directive_extractor.o \
	ft_prct_count.o \
	ft_is_minusf.o \
	ft_is_zerof.o \
	ft_ispercent.o \
	ft_putchar.o \
	ft_putnbr.o \
	ft_putstr.o \
	ft_setdirectives.o \
	ft_strlen.o	

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ) : $(SRCS)
	@$(CC) $(FLAGS) $(HEADER) $(SRCS)

clean :
	@rm -f $(OBJ)
	@rm -f *.gch

fclean : $(OBJ) $(NAME)
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@rm -f *.gch

re : 
	@make clean
	@make fclean
	@make all
