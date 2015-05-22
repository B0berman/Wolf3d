/*
** error.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Wed Dec 17 11:49:49 2014 hugo walbecq
** Last update Thu Dec 18 18:26:33 2014 hugo walbecq
*/

#include	<unistd.h>
#include	"include/wolf3d.h"
#include	"include/my.h"

int		check_buff(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] != '1' && buffer[i] != '\n' &&
          buffer[i] != '0' && buffer[i] != ' ' && buffer[i] != '2')
	{
	  my_putstr("Bad map, invalid characters in file");
	  return (1);
	}
      i++;
    }
  return (0);
}
