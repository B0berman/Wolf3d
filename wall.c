/*
** wall.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Wed Nov 26 15:09:13 2014 hugo walbecq
** Last update Thu Dec 18 16:55:40 2014 hugo walbecq
*/

#include	<math.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"minilibx/mlx.h"
#include	"include/wolf3d.h"
#include	"include/my.h"

float		my_k_two(t_wolf *wolf, float px, float py, float b)
{
  int		y;
  int		len;
  int		x;
  float		k;

  y = 1;
  len = my_strlen(wolf->lab[1]);
  while (y < len)
    {
      k = (y - wolf->y) / (py - wolf->y);
      x = wolf->x + (k * (px - wolf->x));
      if (x > 0 && x < len &&
	  (wolf->lab[x][y] == '1' || wolf->lab[x][y - 1] == '1' ||
	   wolf->lab[x][y] == '2' || wolf->lab[x][y - 1] == '2') &&
	  k < b && k > 0)
	{
	  wolf->color = 0x3F3F3F;
	  if (wolf->lab[x][y] == '2' || wolf->lab[x][y - 1] == '2')
	    wolf->color = 0xFE0202;
 	  b = k;
	}
      y++;
    }
  return (b);
}

float		my_k(t_wolf *wolf, float px, float py)
{
  int		x;
  int		y;
  int		len;
  float		k;
  float		b;

  x = 0;
  len = my_strlen(wolf->lab[0]);
  b = 1000;
  while (x < len)
    {
      k = (x - wolf->x) / (px - wolf->x);
      y = wolf->y + (k * (py - wolf->y));
      if (x > 0 && y > 0 && y < len &&
	  (wolf->lab[x - 1][y] == '1' || wolf->lab[x][y] == '1' ||
	   wolf->lab[x - 1][y] == '2' || wolf->lab[x][y] == '2') &&
	  k < b && k > 0)
	{
	  wolf->color = 0x605F5F;
	  b = k;
	}
      x++;
    }
  b = my_k_two(wolf, px, py, b);
  return (b);
}

int		draw_wall(t_wolf *wolf, int i)
{
  float		px;
  float		py;
  float		a;
  float		tmp;

  a = RAD(wolf->a);
  px = D;
  py = ((float)(P * ((float)(WIN_X / 2) - i)) / WIN_X);
  tmp = px;
  px = (tmp * cos(a)) - (py * sin(a));
  py = (tmp * sin(a)) + (py * cos(a));
  px += wolf->x;
  py += wolf->y;
  wolf->k = my_k(wolf, px, py);
  wolf->x1 = i;
  wolf->y1 = (WIN_Y / 2) - (WIN_Y / (2 * wolf->k));
  wolf->y2 = (WIN_Y / 2) + (WIN_Y / (2 * wolf->k));
  draw_tex(wolf, px, py);
  return (0);
}

void		next_place(t_wolf *wolf, float x, float y)
{
  int		a;
  int		len;
  int		b;
  int		x2;
  int		y2;

  a = x;
  x2 = wolf->x;
  y2 = wolf->y;
  len = my_strlen(wolf->lab[0]);
  b = y;
  // move if doesn't go out or into a wall
  if (x >= 0 && x <= len && y >= 0 &&
      y <= len && wolf->lab[a][b] == '0')
    {
      wolf->x = x;
      wolf->y = y;
    }
  else if (x >= 0 && x <= len && y >= 0 && y <= len &&
	   wolf->lab[a][b] == '2')
    next_lvl(wolf);
  // slide on x
  else if (x >= 0 && x <= len && wolf->lab[a][y2] == '0')
    wolf->x = x;
  // slide on y
  else if (x >= 0 && x <= len && wolf->lab[x2][b] == '0')
    wolf->y = y;
  play_wolf(wolf);
}
