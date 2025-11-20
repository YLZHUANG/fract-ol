/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:02:46 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 16:02:55 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	keys(int keycode, t_pm *pm)
{
	if (keycode == DOWN)
	{
		if (pm->e.fract == BURNINGSHIP)
			pm->e.by0 -= pm->e.bh * 0.2;
		else
			pm->e.by0 += pm->e.bh * 0.2;
		pm->e.by1 = pm->e.by0 - pm->e.bh;
		draw_b(*pm, &(pm->img));
	}
	else if (keycode == UP)
	{
		if (pm->e.fract == BURNINGSHIP)
			pm->e.by0 += pm->e.bh * 0.2;
		else
			pm->e.by0 -= pm->e.bh * 0.2;
		pm->e.by1 = pm->e.by0 - pm->e.bh;
		draw_b(*pm, &(pm->img));
	}
	else if (keycode == LEFT || keycode == RIGHT)
		left_right(keycode, pm);
	else if (keycode == PLUS || keycode == MINUS || keycode == SWITCH)
		img_switch(keycode, pm);
	return (0);
}

void	left_right(int keycode, t_pm *pm)
{
	if (keycode == RIGHT)
	{
		pm->e.bx1 -= pm->e.bw * 0.2;
		pm->e.bx0 = pm->e.bx1 - pm->e.bw;
		draw_b(*pm, &(pm->img));
	}
	else if (keycode == LEFT)
	{
		pm->e.bx1 += pm->e.bh * 0.2;
		pm->e.bx0 = pm->e.bx1 - pm->e.bw;
		draw_b(*pm, &(pm->img));
	}
}

void	img_switch(int keycode, t_pm *pm)
{
	if (keycode == PLUS)
	{
		pm->e.iter += 500;
		draw_b(*pm, &(pm->img));
	}
	else if (keycode == MINUS)
	{
		if (pm->e.iter > 1000)
			pm->e.iter -= 1000;
		else
			pm->e.iter = 20;
		draw_b(*pm, &(pm->img));
	}
	else if (keycode == SWITCH)
	{
		set_colors(pm->e.colors);
		draw_b(*pm, &(pm->img));
	}
}
