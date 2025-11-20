/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:10:52 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/06 15:31:10 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	more_colors(int *colors)
{
	if (colors[0] == 0x470000)
	{
		colors[0] = 0x00005c;
		colors[1] = 0x0040ff;
		colors[2] = 0xffebb0;
		colors[3] = 0xefede7;
	}
	else if (colors[0] == 0x00005c)
	{
		colors[0] = 0x1a321d;
		colors[1] = 0x274732;
		colors[2] = 0xffd891;
		colors[3] = 0xfffdce;
	}
}

void	set_colors(int *colors)
{
	if (colors[0] == 0)
	{
		colors[0] = 0x1c1f36;
		colors[1] = 0x4f5d75;
		colors[2] = 0xef8354;
		colors[3] = 0xbfc0c0;
	}
	else if (colors[0] == 0x1c1f36)
	{
		colors[0] = 0x470000;
		colors[1] = 0xff6700;
		colors[2] = 0xffd300;
		colors[3] = 0xffff00;
	}
	else if (colors[0] == 0x470000 || colors[0] == 0x00005c)
		more_colors(colors);
	else if (colors[0] == 0x1a321d)
	{
		colors[0] = 0;
	}
}

int	interpol(int c1, int c2, float t)
{
	int	r;
	int	g;
	int	b;

	r = ((c2 >> 16) & 0xff) - ((c1 >> 16) & 0xff);
	g = ((c2 >> 8) & 0xff) - ((c1 >> 8) & 0xff);
	b = (c2 & 0xff) - (c1 & 0xff);
	r = r * t + ((c1 >> 16) & 0xff);
	g = g * t + ((c1 >> 8) & 0xff);
	b = b * t + (c1 & 0xff);
	return ((r << 16 | g << 8 | b));
}

int	fancy(t_env e, int i, long double c, long double mz)
{
	float	t;

	if (e.colors[0] == 0)
		return (i * c);
	t = (i + 1 - log(log(sqrt(mz) / log(2)) / log(2))) / e.iter;
	if (t <= 0.15)
		return (interpol(e.colors[0], e.colors[1], t * 10));
	else if (t <= 0.4)
		return (interpol(e.colors[1], e.colors[2], (t - 0.15) * 4));
	else if (t <= 0.75)
		return (interpol(e.colors[2], e.colors[3], (t - 0.4) * 2.5));
	else
		return (interpol(e.colors[3], 0xffffff, (t - 0.75) * 4));
}
