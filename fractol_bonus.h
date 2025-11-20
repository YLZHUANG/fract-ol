/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:11:18 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 14:33:30 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include	"fractol.h"

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

//************ common image creation tools ********************//

void		my_mlx_pixel_put(t_img **img, int x, int y, int color);
long double	convert_x(long double x, t_env e);
long double	convert_y(long double y, t_env e);
t_cp		convert_zoomed(t_cp cp, t_env e);
int			check_cardioid(t_cp cp);

//******************* bonus specifics ************************//

int			mdbrot_b(t_cp t, t_env e, long double c);
int			jsets_b(t_cp t, t_env e, long double c);
int			bnship_b(t_cp t, t_env e, long double c);
int			color_b(t_env e, t_cp t, long double c);
int			draw_b(t_pm pm, t_img *img);
int			mouse_hook(int button, int x, int y, t_pm *pm);
void		many_julia(int x, int y, t_pm *pm);
int			keys(int keycode, t_pm *pm);
void		left_right(int keycode, t_pm *pm);
void		img_switch(int keycode, t_pm *pm);
void		more_colors(int *colors);
void		set_colors(int *colors);
int			interpol(int c1, int c2, float t);
int			fancy(t_env e, int i, long double c, long double mz);

#endif