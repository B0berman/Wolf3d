##
## Makefile for  in /home/walbec_h/rendu/MUL_2014_wolf3d/my_lib
## 
## Made by hugo walbecq
## Login   <walbec_h@epitech.net>
## 
## Started on  Wed Dec 10 17:23:34 2014 hugo walbecq
## Last update Wed Dec 10 17:23:36 2014 hugo walbecq
##

NAME		=	libmy.a

SRC		=	my_getnbr.c		\
			my_strstr.c		\
			my_putchar.c		\
			my_put_nbr.c		\
			my_putstr.c		\
			my_revstr.c		\
			my_strlen.c		\

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			cp my.h ../include

clean		:	
			rm -rf $(OBJ)

fclean		:	clean
			rm $(NAME)

re		:	fclean all
