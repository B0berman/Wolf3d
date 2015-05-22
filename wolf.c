/*
** wolf.c for  in /home/walbec_h/rendu/MUL_2014_wolf3d
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Wed Nov 26 16:09:36 2014 hugo walbecq
** Last update Fri Dec 19 09:59:53 2014 hugo walbecq
*/

#include	<errno.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"minilibx/mlx.h"
#include	"include/my.h"
#include	"include/wolf3d.h"

int		my_map(t_wolf *wolf, char *buffer)
{
  int		i;
  int		l;
  int		n;

  i = 0;
  l = 0;
  n = 0;
  wolf->lab = malloc(sizeof(char *) * (my_strlen(buffer) + 1));
  wolf->lab[0] = malloc(sizeof(char) * ((my_strlen(buffer) / 10) + 1));
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '1' || buffer[i] == '0' || buffer[i] == '2')
	wolf->lab[l][n++] = buffer[i++];
      if (buffer[i] == '\n')
	{
	  wolf->lab[l][n] = '\0';
	  l++;
	  wolf->lab[l] = malloc(sizeof(char) * (n + 1));
	  n = 0;
	  i++;
	}
      if (buffer[i] == ' ')
	i++;
    }
  return (0);
}

int		wolf_map(t_wolf *wolf, int lvl)
{
  int		fd;
  int		nb;
  char		buffer[30000];

  if (lvl == 1)
    if ((fd = open("level/lvl1", O_RDWR)) == -1)
      {
	my_putstr(strerror(errno));
	my_putchar('\n');
	return (1);
      }
  if (lvl == 2)
    if ((fd = open("level/lvl2", O_RDWR)) == -1)
      {
	my_putstr(strerror(errno));
	my_putchar('\n');
	return (1);
      }
  nb = read(fd, buffer, 30000);
  close(fd);
  buffer[nb] = '\0';
  if (check_buff(buffer) == 1 || my_map(wolf, buffer) == 1)
    return (1);
  return (0);
}

void		my_win(t_wolf *wolf, int lvl)
{
  int		x;
  int		y;
  int		tmp;

  tmp = 0;
  if (lvl == 3)
    {
      wolf->img_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,
					    "img/win.xpm", &x, &y);
      wolf->data = mlx_get_data_addr(wolf->img_ptr, &wolf->bpp,
				     &wolf->size_line, &wolf->endian);
    }
  else
    {
      wolf->img_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,
					    "img/lvl2.xpm", &x, &y);
      wolf->data = mlx_get_data_addr(wolf->img_ptr, &wolf->bpp,
				     &wolf->size_line, &wolf->endian);
    }
  while (tmp <= 8000)
    {
      mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr,
			      wolf->img_ptr, 0, 0);
      tmp++;
    }
}

int		next_lvl(t_wolf *wolf)
{
  static int	lvl = 1;

  lvl++;
  if (lvl == 3)
    {
      my_win(wolf, lvl);
      exit(1);
    }
  wolf->c = 1;
  wolf->a = 90;
  wolf->k = -1;
  wolf->x = 1.5;
  wolf->y = 1.5;
  if (lvl != 3)
    {
      my_win(wolf, lvl);
      wolf_map(wolf, lvl);
    }
  return (0);
}
