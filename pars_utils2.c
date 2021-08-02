/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:15:34 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/22 15:15:36 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			setdir(int i, int j, t_settings *set)
{
	set->dirx = 0;
	set->diry = 0;
	set->planex = 0;
	set->planey = 0;
	if (set->map[i][j] == 'N')
	{
		set->dirx = -1;
		set->planey = 0.80;
	}
	if (set->map[i][j] == 'S')
	{
		set->dirx = 1;
		set->planey = -0.80;
	}
	if (set->map[i][j] == 'W')
	{
		set->diry = -1;
		set->planex = -0.80;
	}
	if (set->map[i][j] == 'E')
	{
		set->diry = 1;
		set->planex = 0.80;
	}
}

void			pos_person(t_settings *set)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (set->map[i])
	{
		while (set->map[i][j])
		{
			if (set->map[i][j] == 'N' ||
				set->map[i][j] == 'E' ||
				set->map[i][j] == 'S' ||
				set->map[i][j] == 'W')
			{
				setdir(i, j, set);
				set->posx = i + 0.5;
				set->posy = j + 0.5;
				set->map[i][j] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void			checkfd(t_settings *set)
{
	int			res;
	char		c;

	if (set->fd <= 0)
		errmsg("Can't open file!");
	res = read(set->fd, &c, 1);
	if (res <= 0)
		errmsg("can't read");
}

int				ckeckargs(int ac, char **av, t_settings *set)
{
	int			arglen;
	int			save;

	save = 0;
	if (ac < 2 || ac > 3)
		errmsg("что-то с агументом!");
	arglen = ft_strlen(av[1]);
	if (arglen < 5 || av[1][arglen - 1] != 'b' || av[1][arglen - 2] != 'u'
		|| av[1][arglen - 3] != 'c' || av[1][arglen - 4] != '.')
		errmsg("invalid file!");
	set->fd = open(av[1], O_RDONLY);
	checkfd(set);
	if (ac > 2)
	{
		arglen = ft_strlen(av[2]);
		if (ft_strncmp(av[2], "--save", arglen) == 0 && arglen == 6)
			save = 1;
		else
			errmsg("Wrong argument!");
	}
	return (save);
}

void			struckzr(t_settings *set)
{
	set->er = 0;
	set->resy = 0;
	set->resx = 0;
	set->amnt = 0;
	set->c_color[0] = -1;
	set->c_color[1] = -1;
	set->c_color[2] = -1;
	set->f_color[0] = -1;
	set->f_color[1] = -1;
	set->f_color[2] = -1;
}
