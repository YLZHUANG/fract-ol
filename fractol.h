/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:22:50 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 15:51:02 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include	"mlx/mlx.h"
# include	<stddef.h>
# include	<stdlib.h>
# include	<math.h>
# include	<unistd.h>
# include	<stdio.h>

# define MAX_ITER 500
# define MANDLEBROT 77
# define JULIA 74
# define BURNINGSHIP 283
# define ESC 0xff1b
# define PLUS 0xffab
# define MINUS 0xffad
# define LEFT 0xff51
# define RIGHT 0xff53
# define DOWN 0xff54
# define UP 0xff52
# define SCROLLUP 4
# define SCROLLDOWN 5
# define MOUSELEFT 1
# define SWITCH 99

typedef struct s_cp{
	long double	x;
	long double	y;
}	t_cp;

typedef struct s_env{
	int			width;
	int			height;
	int			iter;
	int			zmcount;
	t_cp		zm;
	long double	zoom;
	long double	bx0;
	long double	bx1;
	long double	bw;
	long double	bh;
	long double	by0;
	long double	by1;
	int			colors[4];
	t_cp		c;
	int			fract;
}	t_env;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_pm
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_env	e;
}	t_pm;

//********************* common tools **************************//

int			is_digit(char *str);
int			is_double(char *str);
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
void		putstr(char	*s);
void		menu(void);
long		get_int(const char *str);
long double	add_precision(char *str, long double res, int l);
long double	get_double(char *str);
long double	mod(t_cp z);
long double	ab(long double d);

//****************** common initiation ************************//

void		basic_env(t_env *e);
void		init_env(t_env *e, int ac, char **ags);
void		j_env(t_env *e, int ac, char **ags);
int			check_args(char *ags2, char *ags3);
void		parsing(int ac, char **ags, t_pm *pm);

//****************** common hooks *****************************//

void		set_scroll(t_pm *pm);
int			cross(t_pm *pm);
int			esc(int keycode, t_pm *pm);

//************ common image creation tools **********************//

void		my_mlx_pixel_put(t_img **img, int x, int y, int color);
long double	convert_x(long double x, t_env e);
long double	convert_y(long double y, t_env e);
t_cp		convert_zoomed(t_cp cp, t_env e);
int			check_cardioid(t_cp cp);

//**************** mandatory specifics **************************//

int			mdbrot(t_cp t, t_env e, long double c);
int			jsets(t_cp t, t_env e, long double c);
int			bnship(t_cp t, t_env e, long double c);
int			get_colors(t_env e, t_cp t, long double c);
int			draw_sets(t_pm pm, t_img *img);
int			precision(int keycode, t_pm *pm);
int			mouse_zoom(int button, int x, int y, t_pm *pm);

#endif