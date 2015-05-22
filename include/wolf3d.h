/*
** wolf3d.h for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_wolf3d
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue Apr 21 19:35:11 2015 walbec_h
** Last update Tue Apr 21 19:37:21 2015 walbec_h
*/

#ifndef		WOLF_H
# define	WOLF_H

# define        ABS(Value)	((Value) < 0 ? - (Value) : (Value))
# define	RAD(a)		(a * M_PI / 180)
# define	M_PI		(3.1415926535)
# define	WIN_X		(1200)
# define	WIN_Y		(900)
# define	D		(0.5)
# define	P		(1)
# define	UP		(65362)
# define	DOWN		(65364)
# define	LEFT		(65363)
# define	RIGHT		(65361)

typedef struct	s_tex
{
  int		bpp;
  int		size_line;
  int		endian;
  unsigned char	*data;
  void		*img_ptr;
}		t_tex;

typedef struct	s_sky
{
  int		bpp;
  int		s_l;
  int		endian;
  unsigned char	*data;
  void		*img_ptr;
}		t_sky;

typedef struct	s_map
{
  int		bpp;
  int		endian;
  int		color;
  int		x1;
  int		y1;
  int		x2;
  int		y2;
  int		sz;
  unsigned char	*data;
  void		*mlx_ptr;
  void		*img_ptr;
}		t_map;

typedef struct	s_wolf
{
  char		**lab;
  int		l;
  int		n;
  int		x1;
  int		y1;
  int		y2;
  int		bpp;
  int		size_line;
  int		endian;
  int		color;
  char		up;
  char		down;
  char		left;
  char		right;
  unsigned char	*data;
  void		*img_ptr;
  void		*win_ptr;
  void		*mlx_ptr;
  int		c;
  float		a;
  float		x;
  float		y;
  float		k;
  t_map		*map;
  t_tex		*tex;
  t_sky		*sky;
}		t_wolf;

float		my_k_two(t_wolf *, float , float , float );
float		my_k(t_wolf *, float , float );
int		my_init(t_wolf *);
int		my_put_image(t_wolf *);
int		next_lvl(t_wolf *);
int		wolf_map(t_wolf *, int );
int		my_map(t_wolf *, char *);
int		my_move(t_wolf *);
int		my_key_press(int , t_wolf *);
int		my_key_release(int , t_wolf *);
int		draw_sky(t_wolf *, int );
int		draw_wall(t_wolf *, int );
int		draw_ground(t_wolf *, int );
int		gere_expose(t_wolf *);
int		gere_key(int , t_wolf *);
int             my_pixel_put_to_image(t_wolf *, int , int );
int		check_buff(char *);
void		draw_min_map(t_wolf *);
void		lvl_two(t_wolf *);
void		play_wolf(t_wolf *);
void		draw_tex(t_wolf *, float , float );
void		my_put_tex_to_image(int , t_wolf *);
void		next_place(t_wolf *, float , float );
void		my_draw_one(t_wolf *, int );
void		my_draw_two(t_wolf *, int );

#endif		/* !WOLF_H */
