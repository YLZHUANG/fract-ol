/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:04:41 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 14:21:45 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_scroll(t_pm *pm)
{
	pm->e.bx0 = pm->e.zm.x - ((pm->e.zm.x - pm->e.bx0) / pm->e.zoom);
	pm->e.bx1 = ((pm->e.bx1 - pm->e.zm.x) / pm->e.zoom) + pm->e.zm.x;
	pm->e.bw = pm->e.bx1 - pm->e.bx0;
	pm->e.by0 = ((pm->e.by0 - pm->e.zm.y) / pm->e.zoom) + pm->e.zm.y;
	pm->e.by1 = pm->e.zm.y - ((pm->e.zm.y - pm->e.by1) / pm->e.zoom);
	pm->e.bh = pm->e.by0 - pm->e.by1;
}

int	cross(t_pm *pm)
{
	mlx_destroy_image(pm->mlx, pm->img.img);
	mlx_destroy_window(pm->mlx, pm->win);
	mlx_destroy_display(pm->mlx);
	free(pm->mlx);
	exit(0);
	return (0);
}

int	esc(int keycode, t_pm *pm)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(pm->mlx, pm->img.img);
		mlx_destroy_window(pm->mlx, pm->win);
		mlx_destroy_display(pm->mlx);
		free(pm->mlx);
		exit(0);
	}
	return (0);
}
