/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:12:03 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 12:56:36 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	basic_env(t_env *e)
{
	e->iter = MAX_ITER;
	e->zmcount = 0;
	e->zm.x = -1.4010;
	e->zm.y = 0;
	if (e->fract == JULIA)
	{
		e->zm.x = 0.5;
		e->zm.y = -0.187083;
	}
	e->zoom = 1;
	e->bx0 = -2;
	e->bx1 = 2;
	e->bw = e->bx1 - e->bx0;
	e->bh = e->bw * e->height / e->width;
	e->by0 = e->bh / 2;
	e->by1 = e->by0 * -1;
	e->colors[0] = 0;
	if (e->fract == MANDLEBROT)
	{
		e->bx0 = -2.5;
		e->bx1 = 1.5;
	}
}

void	j_env(t_env *e, int ac, char **ags)
{
	if (ac == 4)
	{
		e->c.x = get_double(ags[2]);
		e->c.y = get_double(ags[3]);
	}
	else if (ac == 6)
	{
		e->c.x = get_double(ags[2]);
		e->c.y = get_double(ags[3]);
		e->width = atoi(&ags[4][1]);
		e->height = atoi(&ags[5][1]);
	}
}

void	init_env(t_env *e, int ac, char **ags)
{
	e->width = 400;
	e->height = 400;
	e->c.x = 0.285;
	e->c.y = 0;
	if (!ft_strcmp(ags[1], "J"))
		e->fract = JULIA;
	else if (!ft_strcmp(ags[1], "B"))
		e->fract = BURNINGSHIP;
	else if (!ft_strcmp(ags[1], "M"))
		e->fract = MANDLEBROT;
	if (ac == 4 && e->fract != JULIA)
	{
		e->width = atoi(&ags[2][1]);
		e->height = atoi(&ags[3][1]);
	}
	else if (e->fract == JULIA)
		j_env(e, ac, ags);
	basic_env(e);
}

int	check_args(char *ags2, char *ags3)
{
	if ((ags2[0] == 'W' && ags3[0] == 'H' && is_digit(&ags2[1])
			&& is_digit(&ags3[1])))
		return (1);
	else
		return (0);
}

void	parsing(int ac, char **ags, t_pm *pm)
{
	if (ac > 1 && (!ft_strcmp(ags[1], "J") || !ft_strcmp(ags[1], "M")
			|| !ft_strcmp(ags[1], "B")))
	{
		if (ac == 2 || (ac == 4 && ((ft_strcmp(ags[1], "J") != 0
						&& check_args(ags[2], ags[3]))
					|| (!ft_strcmp(ags[1], "J")
						&& is_double(ags[2]) >= 0 && is_double(ags[3]) >= 0)))
			|| ((ac == 6 && !ft_strcmp(ags[1], "J") && is_double(ags[2]) >= 0
					&& is_double(ags[3]) >= 0 && check_args(ags[4], ags[5]))))
		{
			init_env(&(pm->e), ac, ags);
		}
		else
			menu();
	}
	else
		menu();
}
