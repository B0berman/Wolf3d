/*
** my_strlen.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 19 10:13:34 2014 hugo walbecq
** Last update Fri Dec 19 10:13:35 2014 hugo walbecq
*/

int	my_strlen(char *str)
{
  int	y;

  y = 0;
  while (str[y] != '\0')
    y++;
  return (y);
}
