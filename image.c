/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:11:45 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/06 14:11:58 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img **img, int x, int y, int color)
{
	char	*dst;

	dst = (*img)->addr + (y * (*img)->line_len + x * ((*img)->bpp / 8));
	*(unsigned int *)dst = color;
}

long double	convert_x(long double x, t_env e)
{
	x = e.bx0 + (e.bw * x / e.width);
	return (x);
}

long double	convert_y(long double y, t_env e)
{
	y = e.by0 - (e.bh * y / e.height);
	return (y);
}

t_cp	convert_zoomed(t_cp cp, t_env e)
{
	cp.x = e.bx0 + (e.bw * cp.x / e.width);
	cp.y = e.by0 - (e.bh * cp.y / e.height);
	return (cp);
}

int	check_cardioid(t_cp cp)
{
	int			res;
	long double	q;

	res = 0;
	q = cp.x - 0.25;
	q = q * q + cp.y * cp.y;
	if (q * (q + (cp.x - 0.25)) <= (cp.y * cp.y) * 0.25)
		res = 1;
	return (res);
}
