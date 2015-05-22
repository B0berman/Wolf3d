/*
** my_putstr.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 19 09:56:03 2014 hugo walbecq
** Last update Fri Dec 19 09:56:05 2014 hugo walbecq
*/

int	my_putstr(char *str)
{
  int	y;

  y = 0;
  while (str[y] != '\0')
    {
      my_putchar(str[y]);
      y++;
    }
}
