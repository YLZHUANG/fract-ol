/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:12:51 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/07 14:22:50 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_double(char *str)
{
	int	i;
	int	c;
	int	s;

	s = 0;
	c = 0;
	i = 0;
	if (str[0] == '.')
		return (-1);
	if (str[i] == '-')
			i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			c = i;
			s++;
		}
		if (((str[i] < '0' || str[i] > '9') && str[i] != '.') || s > 1)
			return (-1);
		i++;
	}
	if (s == 0)
		return (0);
	return (c);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
		return (s1[i] - s2[i]);
	return (0);
}
