/*
** my_put_nbr.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 19 09:55:45 2014 hugo walbecq
** Last update Fri Dec 19 09:55:47 2014 hugo walbecq
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  if ((nb < 10 && nb > 0) ||
      (nb > -10 && nb < 0) || nb == 0)
    {
      if (nb < 0)
        {
          my_putchar('-');
          my_putchar(-nb + 48);
        }
      else
        my_putchar(nb + 48);
    }
  else
    {
      my_put_nbr(nb / 10);
      if (nb > 0)
        my_putchar(nb % 10 + 48);
      else
        my_putchar(nb % 10 * -1 + 48);
    }
}
