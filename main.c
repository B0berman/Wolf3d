/*
** main.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Wed Nov 26 13:57:25 2014 hugo walbecq
** Last update Mon Feb  2 13:50:38 2015 hugo walbecq
*/

#include	</usr/include/X11/X.h>
#include	<stdlib.h>
#include	"minilibx/mlx.h"
#include	"include/my.h"
#include	"include/wolf3d.h"

void		play_wolf(t_wolf *wolf)
{
  int		i;

  i = 0;
  while (i < WIN_X)
    {
      draw_sky(wolf, i);
      draw_ground(wolf, i);
      draw_wall(wolf, i);
      i++;
    }
  draw_min_map(wolf);
  mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr, 0, 0);
}

int		my_init(t_wolf *wolf)
{
  t_map		*map;

  map = malloc(sizeof(t_map));
  if ((wolf->mlx_ptr = mlx_init()) == NULL ||
      (map->mlx_ptr = mlx_init()) == NULL || wolf_map(wolf, 1) == 1)
    return (1);
  wolf->c = 1;
  wolf->a = 0;
  wolf->k = -1;
  wolf->x = 1.5;
  wolf->y = 1.5;
  wolf->up = '0';
  wolf->down = '0';
  wolf->right = '0';
  wolf->left = '0';
  wolf->img_ptr = mlx_new_image(wolf->mlx_ptr, WIN_X, WIN_Y);
  wolf->win_ptr = mlx_new_window(wolf->mlx_ptr, WIN_X, WIN_Y, "Wolf3d");
  wolf->data = mlx_get_data_addr(wolf->img_ptr, &wolf->bpp,
				 &wolf->size_line, &wolf->endian);
  map->img_ptr = mlx_new_image(map->mlx_ptr, 200, 200);
  map->data = mlx_get_data_addr(map->img_ptr, &map->bpp,
				 &map->sz, &map->endian);
  wolf->map = map;
  return (0);
}

int		main()
{
  t_wolf	wolf;
  int		img_x;
  int		img_y;
  int		sx;
  int		sy;
  t_tex		tex;
  t_sky		sky;

  if ((my_init(&wolf)) == 1)
    return (0);
  tex.img_ptr =  mlx_xpm_file_to_image(wolf.mlx_ptr,
				       "img/murr.xpm", &img_x, &img_y);
  tex.data = mlx_get_data_addr(tex.img_ptr,
			       &tex.bpp, &tex.size_line, &tex.endian);
  sky.img_ptr =  mlx_xpm_file_to_image(wolf.mlx_ptr, "img/sky.xpm", &sx, &sy);
  sky.data = mlx_get_data_addr(sky.img_ptr, &sky.bpp, &sky.s_l, &sky.endian);
  wolf.sky = &sky;
  wolf.tex = &tex;
  play_wolf(&wolf);
  mlx_hook(wolf.win_ptr, KeyPress, KeyPressMask, my_key_press, &wolf);
  mlx_hook(wolf.win_ptr, KeyRelease, KeyReleaseMask, my_key_release, &wolf);
  mlx_loop_hook(wolf.mlx_ptr, my_move, &wolf);
  mlx_expose_hook(wolf.win_ptr, gere_expose, &wolf);
  mlx_loop(wolf.mlx_ptr);
  return (0);
}
