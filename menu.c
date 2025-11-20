/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:37:33 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 12:44:02 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putstr(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	menu(void)
{
	putstr("MENU : FRACTALS       OPTIONS\n");
	putstr("M    : Mandelbrot     W{100, 800} H{100, 800};\n");
	putstr("J    : Julia          {double} {double} W{100, 800} H{100, 800};\n");
	putstr("B    : Burningship    W{100, 800} H{100, 800};\n");
	exit(0);
}
