/*
** my_env.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 12 15:01:33 2014 hugo walbecq
** Last update Fri Dec 19 09:57:07 2014 hugo walbecq
*/

#include	<unistd.h>
#include	"minilibx/mlx.h"
#include	"include/wolf3d.h"

int		draw_sky(t_wolf *wolf, int i)
{
  int		locate_sky;
  int		locate_i;
  int		x;
  int		a;

  a = 2400 / 360 * (360 - ((int)wolf->a % 360));
  wolf->x1 = i;
  x = a + i;
  wolf->y1 = 0;
  wolf->y2 = 450;
  while (wolf->y1 <= wolf->y2)
    {
      locate_i = (wolf->size_line * wolf->y1) + (wolf->x1 * (wolf->bpp / 8));
      locate_sky = (wolf->sky->s_l * wolf->y1) + (x * 4);
      if (wolf->y1 >= 0 && wolf->y1 < WIN_Y)
        {
	  wolf->data[locate_i++] = wolf->sky->data[locate_sky];
	  wolf->data[locate_i++] = wolf->sky->data[locate_sky + 1];
	  wolf->data[locate_i] = wolf->sky->data[locate_sky + 2];
        }
      wolf->y1 += 1;
      if (wolf->y1 > WIN_Y)
        return (0);
    }
  return (0);
}

int		draw_ground(t_wolf *wolf, int i)
{
  int		y;

  wolf->x1 = i;
  y = (WIN_Y / 2);
  wolf->y2 = WIN_Y;
  wolf->color = 0x3F3F3F;
  while (y <= wolf->y2)
    {
      my_pixel_put_to_image(wolf, wolf->x1, y);
      y++;
    }
  return (0);
}
