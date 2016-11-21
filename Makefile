#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:55:01 by jcarra            #+#    #+#              #
#    Updated: 2016/11/21 09:34:29 by jcarra           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit

SRC			=	ft_main.c \
				ft_fillit.c \
				ft_secure.c \
				ft_parsing.c \
				ft_prosecure.c \
				ft_read.c \
				ft_algo.c \
				ft_algo_tools.c

LIB			=	libft.a

DIRSRC		=	sources/
DIRLIB		=	library/
DIRINC		=	include/

SRCS		=	$(SRC:%=$(DIRSRC)%)
LIBS		=	$(LIB:%=$(DIRLIB)%)
OBJS		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -I./$(DIRINC)

CC			=	gcc
RM			=	rm -f
ECHO		=	printf
MAKE		=	make -C


all		:		$(NAME)

$(NAME)	:
				@$(MAKE) $(DIRLIB)
				@$(CC) $(CFLAGS) -c $(SRCS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
				@$(ECHO) '\033[32m> Compiled\n\033[0m'

clean	:
				@$(MAKE) $(DIRLIB) clean
				@$(RM) $(OBJS)
				@$(ECHO) '\033[31m> Directory cleaned\n\033[0m'

fclean	:		clean
				@$(MAKE) $(DIRLIB) fclean
				@$(RM) $(NAME)
				@$(ECHO) '\033[31m> Remove executable\n\033[0m'

re		:		fclean all

.PHONY	:		all clean fclean re