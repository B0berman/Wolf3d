/*
** minimap.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue Dec 16 10:59:06 2014 hugo walbecq
** Last update Fri Dec 19 09:56:50 2014 hugo walbecq
*/

#include	"include/wolf3d.h"
#include	"minilibx/mlx.h"
#include	"include/my.h"

void		my_pixel_put_to_map(t_wolf *wolf, int x, int y)
{
  int           locate;
  int           a;

  locate = (wolf->map->sz * y) + (x * 4);
  a = mlx_get_color_value(wolf->map->mlx_ptr, wolf->map->color);
  wolf->map->data[locate] = a & 255;
  wolf->map->data[locate + 1] = a >> 8 & 255;
  wolf->map->data[locate + 2] = a >> 16 & 255;
}

void		draw_square(t_wolf *wolf)
{
  int		x;
  int		y;

  y = wolf->map->y1;
  wolf->map->y2 = wolf->map->y1 + 20;
  while (y <= wolf->map->y2)
    {
      x = wolf->map->x1;
      wolf->map->x2 = x + 20;
      while (x <= wolf->map->x2)
	{
	  my_pixel_put_to_map(wolf, x, y);
	  x++;
	}
      y++;
    }
}

void		check_pos(t_wolf *wolf, int x, int y)
{
  int		len;

  len = my_strlen(wolf->lab[0]);
  if (x < 0 || y < 0 || x > len || y > len)
    wolf->map->color = 0x010101;
  else
    {
      if (wolf->lab[x][y] == '1')
	wolf->map->color = 0x010101;
      if (wolf->lab[x][y] == '2')
	wolf->map->color = 0x01FF23;
      if (wolf->lab[x][y] == '0')
	wolf->map->color = 0xFFFFFF;
      if (x == (int)wolf->x && y == (int)wolf->y)
	wolf->map->color = 0xFF0101;
      if (wolf->map->y1 == 180)
	wolf->map->color = 0x010101;
    }
}

void		draw_min_map(t_wolf *wolf)
{
  int		x;
  int		y;

  wolf->map->y1 = 0;
  wolf->map->color = 0x010101;
  y = wolf->y - 4;
  while (y <= (wolf->y + 5))
    {
      wolf->map->x1 = 0;
      x = wolf->x - 4;
      while (x <= (wolf->x + 5))
	{
	  check_pos(wolf, x, y);
	  draw_square(wolf);
	  x++;
	  wolf->map->x1 += 20;
	}
      y++;
      wolf->map->y1 += 20;
    }
  mlx_put_image_to_window(wolf->map->mlx_ptr,
			  wolf->win_ptr,
			  wolf->map->img_ptr, 1, 700);
}
