/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:11:00 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 14:29:26 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mdbrot_b(t_cp t, t_env e, long double c)
{
	int			i;
	long double	tzx;
	t_cp		z;

	i = 0;
	e.c = t;
	z.x = 0;
	z.y = 0;
	e.c = convert_zoomed(e.c, e);
	if (check_cardioid(e.c))
		return (0);
	while (mod(z) < 4 && i < e.iter)
	{
		tzx = z.x;
		z.x = tzx * tzx - z.y * z.y + e.c.x;
		z.y = 2 * tzx * z.y + e.c.y;
		i++;
	}
	if (mod(z) < 4 && i == e.iter)
		return (0);
	else
		return (fancy(e, i, c, mod(z)));
}	

int	jsets_b(t_cp t, t_env e, long double c)
{
	int			i;
	long double	tzx;
	t_cp		z;

	i = 0;
	if (e.c.x < 0 || e.c.y < 0)
		t.y = e.height - t.y;
	z = convert_zoomed(t, e);
	while (mod(z) < 4 && i < e.iter)
	{
		tzx = z.x;
		z.x = tzx * tzx - z.y * z.y + e.c.x;
		z.y = 2 * tzx * z.y + e.c.y;
		i++;
	}
	if (mod(z) < 4 && i == e.iter)
		return (0);
	else
		return (fancy(e, i, c, mod(z)));
}

int	bnship_b(t_cp t, t_env e, long double c)
{
	int			i;
	t_cp		z;
	long double	tzx;

	i = 0;
	t.y = e.height - t.y;
	e.c = t;
	z.x = 0;
	z.y = 0;
	e.c = convert_zoomed(e.c, e);
	while (mod(z) < 4 && i < e.iter)
	{
		tzx = ab(z.x);
		z.y = ab(z.y);
		z.x = tzx * tzx - z.y * z.y + e.c.x;
		z.y = 2 * tzx * z.y + e.c.y;
		i++;
	}
	if (mod(z) < 4 && i == e.iter)
		return (0);
	else
		return (fancy(e, i, c, mod(z)));
}

int	color_b(t_env e, t_cp t, long double c)
{
	int	color;

	color = 0;
	if (e.fract == MANDLEBROT)
		color = mdbrot_b(t, e, c);
	else if (e.fract == JULIA)
		color = jsets_b(t, e, c);
	else if (e.fract == BURNINGSHIP)
		color = bnship_b(t, e, c);
	return (color);
}			

int	draw_b(t_pm pm, t_img *img)
{
	t_cp		pixel;
	t_cp		t;
	long double	c;

	pixel.x = 0;
	c = 0x111111 / pm.e.iter;
	while (pixel.x < pm.e.width)
	{
		pixel.y = 0;
		while (pixel.y < pm.e.height)
		{
			t = pixel;
			my_mlx_pixel_put(&img, pixel.x, pixel.y, color_b(pm.e, t, c));
			pixel.y++;
		}
		pixel.x++;
	}
	mlx_put_image_to_window(pm.mlx, pm.win, img->img, 0, 0);
	return (0);
}
