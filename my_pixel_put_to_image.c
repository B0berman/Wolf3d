/*
** my_pixel_put_to_image.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 12 15:01:15 2014 hugo walbecq
** Last update Wed Dec 24 21:51:57 2014 hugo walbecq
*/

#include	"minilibx/mlx.h"
#include	"include/wolf3d.h"

int		my_pixel_put_to_image(t_wolf *wolf, int x, int y)
{
  int		locate;
  int		a;

  locate = (wolf->size_line * y) + (x * wolf->bpp / 8);
  a = mlx_get_color_value(wolf->mlx_ptr, wolf->color);
  wolf->data[locate] = a & 255;
  wolf->data[locate + 1] = a >> 8 & 255;
  wolf->data[locate + 2] = a >> 16 & 255;
  return (0);
}

void		draw_tex(t_wolf *wolf, float px, float py)
{
  float		posx;
  float		posy;
  int		tx;

  posx = (px - wolf->x) * wolf->k + wolf->x;
  posy = (py - wolf->y) * wolf->k + wolf->y;
  tx = (1 - (posy - (int)posy)) * 128;
  if (wolf->color == 0x3F3F3F)
    tx = (1 - (posx - (int)posx)) * 128;
  my_put_tex_to_image(tx, wolf);
}

void		put_pix_of_tex(t_wolf *wolf, int locate_i, int locate_t)
{
  if (wolf->k >= 1)
    {
      wolf->data[locate_i++] = wolf->tex->data[locate_t] / wolf->k;
      wolf->data[locate_i++] = wolf->tex->data[locate_t + 1] / wolf->k;
      wolf->data[locate_i] = wolf->tex->data[locate_t + 2] / wolf->k;
    }
  else
    {
      wolf->data[locate_i++] = wolf->tex->data[locate_t];
      wolf->data[locate_i++] = wolf->tex->data[locate_t + 1];
      wolf->data[locate_i] = wolf->tex->data[locate_t + 2];
    }
}

void		my_put_tex_to_image(int tx, t_wolf *wolf)
{
  int		ty;
  int		locate_t;
  int		locate_i;
  int		h;

  h = (wolf->y2 - wolf->y1);
  if (wolf->y1 < 0)
    wolf->y1 = 0;
  while (wolf->y1 <= wolf->y2)
    {
      ty = (wolf->y1 * 2 - WIN_Y + h) * 69 / h;
      locate_t = (wolf->tex->size_line * ty) + (tx * 4);
      locate_i = (wolf->size_line * wolf->y1) + (wolf->x1 * 4);
      if (wolf->y1 >= 0 && wolf->y1 < WIN_Y && ty >= 0 &&
	  tx <= 128 && tx >= 0 && ty <= 128)
	put_pix_of_tex(wolf, locate_i, locate_t);
      wolf->y1 += 1;
      if (wolf->y1 > WIN_Y)
	return ;
    }
}
