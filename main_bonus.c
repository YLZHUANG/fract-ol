/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:12:18 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 16:22:44 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_hook(int button, int x, int y, t_pm *pm)
{
	if (pm->e.fract == BURNINGSHIP
		|| (pm->e.fract == JULIA && (pm->e.c.x < 0 || pm->e.c.y < 0)))
		y = pm->e.height - y;
	if (button == SCROLLUP)
	{
		pm->e.zoom = 1.5;
		pm->e.zmcount++;
		pm->e.zm.x = convert_x(x, pm->e);
		pm->e.zm.y = convert_y(y, pm->e);
		set_scroll(pm);
		draw_b(*pm, &(pm->img));
	}
	else if (button == SCROLLDOWN)
	{
		pm->e.zoom = 0.8;
		pm->e.zmcount--;
		pm->e.zm.x = convert_x(x, pm->e);
		pm->e.zm.y = convert_y(y, pm->e);
		set_scroll(pm);
		draw_b(*pm, &(pm->img));
	}
	else if (button == 1 && pm->e.fract == JULIA && pm->e.colors[0] == 0x470000)
		many_julia(x, y, pm);
	return (0);
}

void	many_julia(int x, int y, t_pm *pm)
{
	pm->e.zoom = 1;
	pm->e.c.x = convert_x(x, pm->e);
	pm->e.c.y = convert_y(y, pm->e);
	set_scroll(pm);
	draw_b(*pm, &(pm->img));
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
	pm.win = mlx_new_window(pm.mlx, pm.e.width, pm.e.height, "FRACTOL BONUS");
	pm.img.img = mlx_new_image(pm.mlx, pm.e.width, pm.e.height);
	pm.img.addr = mlx_get_data_addr(pm.img.img, &pm.img.bpp, &pm.img.line_len,
			&pm.img.endian);
	draw_b(pm, &(pm.img));
	mlx_mouse_hook(pm.win, &mouse_hook, &pm);
	mlx_hook(pm.win, 17, 0, &cross, &pm);
	mlx_hook(pm.win, 2, 1L << 0, &esc, &pm);
	mlx_hook(pm.win, 3, 1L << 1, &keys, &pm);
	mlx_loop(pm.mlx);
}
