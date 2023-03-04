/*
** key_expose.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Dec 19 09:50:13 2014 hugo walbecq
** Last update Tue Feb  3 10:55:20 2015 hugo walbecq
*/

#include        "minilibx/mlx.h"
#include	<math.h>
#include	<stdlib.h>
#include        "include/wolf3d.h"
#include        "include/my.h"

int		gere_expose(t_wolf *wolf)
{
  mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr,
                          wolf->img_ptr, 0, 0);
  return (0);
}

int		my_key_press(int key_code, t_wolf *wolf)
{
  if (key_code == 65307)
    {
      free(wolf->lab);
      free(wolf->map);
      exit(1);
    }
  if (key_code == UP && wolf->up != '1')
    wolf->up = '1';
  if (key_code == DOWN && wolf->down != '1')
    wolf->down = '1';
  if (key_code == LEFT && wolf->left != '1')
      wolf->left = '1';
  if (key_code == RIGHT && wolf->right != '1')
      wolf->right = '1';
  return (0);
}

int		my_key_release(int key_code, t_wolf *wolf)
{
  if (key_code == UP && wolf->up != '0')
    {
      wolf->up = '0';
    }
  if (key_code == DOWN && wolf->down != '0')
    {
      wolf->down = '0';
    }
  if (key_code == LEFT && wolf->left != '0')
      wolf->left = '0';
  if (key_code == RIGHT && wolf->right != '0')
      wolf->right = '0';
  return (0);
}

int		my_move(t_wolf *wolf)
{
  float		x;
  float		y;

  x = -1;
  y = -1;
  if (wolf->up == '1')
    {
      x = wolf->x + 0.04 * cos(RAD(wolf->a));
      y = wolf->y + 0.04 * sin(RAD(wolf->a));
    }
  if (wolf->down == '1')
    {
      x = wolf->x - 0.04 * cos(RAD(wolf->a));
      y = wolf->y - 0.04 * sin(RAD(wolf->a));
    }
  if (wolf->left == '1')
    wolf->a = wolf->a - 3;
  if (wolf->right == '1')
    wolf->a = wolf->a + 3;
  next_place(wolf, x, y);
  return (0);
}
