##
## Makefile for  in /home/walbec_h/rendu/MUL_2014_wolf3d
## 
## Made by hugo walbecq
## Login   <walbec_h@epitech.net>
## 
## Started on  Wed Nov 26 14:21:11 2014 hugo walbecq
## Last update Thu Mar 19 15:37:31 2015 hugo walbecq
##

NAME            =       wolf3d

SRC             =       main.c\
			wolf.c\
			error.c\
			minimap.c\
			my_env.c\
			wall.c\
			key_expose.c\
			my_pixel_put_to_image.c\

OBJ             =       $(SRC:.c=.o)

LIBFLAGS	=	-L my_lib/ \
			-lmy \
			-L/usr/X11R6/lib

CFLAGS          +=      -Wall\
                        -Wextra\
                        -ansi\
                        -pedantic

all             :       $(NAME)

$(NAME)         :       $(OBJ)
			cc -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS) -L./minilibx/ -lmlx_ -L/opt/X11 -lXext -lX11 -lm -L. my_lib/libmy.a

lib		:	
			make re -C my_lib/
clean           :
			rm -rf $(OBJ)
			make clean -C my_lib/

fclean          :       clean
			rm -rf $(NAME)

re              :       lib fclean all
