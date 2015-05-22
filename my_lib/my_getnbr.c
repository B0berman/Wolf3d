/*
** my_getnbr.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 19 09:55:03 2014 hugo walbecq
** Last update Fri Dec 19 09:55:07 2014 hugo walbecq
*/

int		my_getnbr(char *str)
{
  double	x;
  int		y;
  int		z;

  z = 1;
  x = 0;
  y = 0;
  while (str[y] == '-' || str[y] == '+' ||
	 str[y] < '0' || str[y] > '9')
    {
      if (str[y] == '-')
	z *= -1;
      y++;
    }
  while (str[y] != '\0' && str[y] >= '0' && str[y] <= '9')
    {
      x = (x * 10);
      x = (str[y] - 48) + x;
      y++;
    }
  if (z == -1)
    x *= -1;
  if (x < -2147483648 || x > 2147483647)
    return (0);
  return ((int)x);
}
