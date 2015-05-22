/*
** my_revstr.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 19 10:13:18 2014 hugo walbecq
** Last update Fri Dec 19 10:13:24 2014 hugo walbecq
*/

char	*my_revstr(char *str)
{
  int	x;
  int	i;
  int	y;
  int	w;

  x = 0;
  i = 0;
  while (str[x] != '\0')
    x++;
  x--;
  while (i < x)
    {
      y = str[x];
      str[x] = str[i];
      str[i] = y;
      i++;
      x--;
    }
  return (str);
}
