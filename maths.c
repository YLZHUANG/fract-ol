/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:11:34 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/06 19:04:04 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long	get_int(const char *str)
{
	int		s;
	long	res;

	s = 1;
	res = 0;
	if (*str && *str == '-')
	{
		s *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (s < 0)
		res = -res;
	return (res);
}

long double	add_precision(char *str, long double res, int l)
{
	while (l)
	{
		res /= 10;
		l--;
	}
	if (str[0] == '-')
		res = get_int(str) - res;
	else
		res += get_int(str);
	return (res);
}

long double	get_double(char *str)
{
	int			i;
	int			l;
	long double	res;

	i = is_double(str) + 1;
	l = ft_strlen(str) - i;
	res = 0;
	if (str[i] == '0')
	{
		while (str[i] == '0')
			i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res = add_precision(str, res, l);
	return (res);
}

long double	mod(t_cp z)
{
	long double	res;

	res = z.x * z.x + z.y * z.y;
	return (res);
}

long double	ab(long double d)
{
	if (d < 0)
		d *= -1;
	return (d);
}
