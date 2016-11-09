#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:55:01 by jcarra            #+#    #+#              #
#    Updated: 2016/11/09 12:45:03 by jcarra           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit

SRC			=	ft_main.c \
				ft_fillit.c \
				ft_secure.c \
				ft_read.c

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


all		:		$(NAME)
			   	@$(ECHO) ''

$(NAME)	:
				@$(CC) $(CFLAGS) -c $(SRCS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
				@$(ECHO) '\033[32m> Compiled\n\033[0m'

clean	:
				@$(RM) $(OBJS)
				@$(ECHO) '\033[31m> Directory cleaned\n\033[0m'

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) '\033[31m> Remove executable\n\033[0m'

re		:		fclean all

.PHONY	:		all clean fclean re
