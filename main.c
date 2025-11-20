/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:19:49 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 14:28:42 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	precision(int keycode, t_pm *pm)
{
	if (keycode == PLUS)
	{
		pm->e.iter += 500;
		draw_sets(*pm, &(pm->img));
	}
	else if (keycode == MINUS)
	{
		if (pm->e.iter > 1000)
			pm->e.iter -= 1000;
		else
			pm->e.iter = 20;
		draw_sets(*pm, &(pm->img));
	}
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_pm *pm)
{
	(void)x;
	(void)y;
	if (button == SCROLLUP)
	{
		pm->e.zoom = 1.5;
		pm->e.zmcount++;
		set_scroll(pm);
		draw_sets(*pm, &(pm->img));
	}
	else if (button == SCROLLDOWN)
	{
		pm->e.zoom = 0.8;
		pm->e.zmcount--;
		set_scroll(pm);
		draw_sets(*pm, &(pm->img));
	}
	return (0);
}

int	main(int ac, char **ags)
{
	t_pm	pm;

	parsing(ac, ags, &pm);
	pm.mlx = mlx_init();
	if (pm.mlx == NULL)
	{
		perror("mlx_init() failed");
		exit(1);
	}
	pm.win = mlx_new_window(pm.mlx, pm.e.width, pm.e.height, "FRACTOL");
	pm.img.img = mlx_new_image(pm.mlx, pm.e.width, pm.e.height);
	pm.img.addr = mlx_get_data_addr(pm.img.img, &pm.img.bpp, &pm.img.line_len,
			&pm.img.endian);
	draw_sets(pm, &(pm.img));
	mlx_mouse_hook(pm.win, &mouse_zoom, &pm);
	mlx_hook(pm.win, 17, 0, &cross, &pm);
	mlx_hook(pm.win, 2, 1L << 0, &esc, &pm);
	mlx_hook(pm.win, 3, 1L << 1, &precision, &pm);
	mlx_loop(pm.mlx);
}
