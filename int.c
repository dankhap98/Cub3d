/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:12:06 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/22 22:12:12 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		intres(char **xy)
{
	int		i;
	int		j;

	i = 0;
	while (xy[i])
	{
		j = 0;
		while (xy[i][j])
		{
			if (!(ft_isdigit(xy[i][j])))
				errmsg("ivalid resolution");
			j++;
		}
		i++;
	}
}

void		intcolor(char **rgb)
{
	int		i;
	char	*tmp;

	i = 0;
	while (rgb[i])
	{
		tmp = ft_strtrim(rgb[i], " ");
		if (ft_strrchr(tmp, ' '))
			errmsg("ivalid color");
		if (ft_strlen(tmp) > 9 || ft_atoi(tmp) > 255)
			errmsg("ivvalid color");
		free(tmp);
		i++;
	}
}

void		restomax2(t_settings *set, char **xy, int *c)
{
	if (ft_atoi(xy[0]) < 50 || ft_atoi(xy[1]) < 50)
		errmsg("to small resolution!");
	if ((ft_strlen(xy[0]) - c[0]) > 5 || ft_atoi(xy[0]) > 20000)
		set->resx = 20000;
	else
		set->resx = ft_atoi(xy[0]);
	if ((ft_strlen(xy[1]) - c[1]) > 5 || ft_atoi(xy[1]) > 20000)
		set->resy = 20000;
	else
		set->resy = ft_atoi(xy[1]);
}

void		restomax(t_settings *set, char **xy)
{
	int		i;
	int		j;
	int		c[2];

	i = 0;
	c[0] = 0;
	c[1] = 0;
	while (xy[i])
	{
		j = -1;
		if (ft_strlen(xy[i]) > 5)
		{
			while (xy[i][++j])
			{
				if (xy[i][j] == '0')
					c[i]++;
				else
					break ;
			}
		}
		i++;
	}
	restomax2(set, xy, c);
}
