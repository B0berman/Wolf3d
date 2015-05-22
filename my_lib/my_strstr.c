/*
** my_strstr.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 19 10:13:44 2014 hugo walbecq
** Last update Fri Dec 19 10:13:49 2014 hugo walbecq
*/

#include	<stdio.h>

char		*my_strstr(char *str, char *to_find)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      while (str[i] == to_find[j])
	{
	  j++;
	  if (to_find[j] == '\0')
	    {
	      i = i - (j - 1);
	      return (str + i);
	    }
	}
      i++;
    }
  return (NULL);
}
