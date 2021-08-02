/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:13:20 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/21 22:13:23 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				checkparams(t_settings *set)
{
	t_settings	*typs;

	typs = set;
	if (typs->resx < 0 || typs->resy < 0 || typs->fd < 0 ||
		typs->f_color < 0 || typs->path_no == NULL ||
		typs->path_ea == NULL || typs->path_we == NULL ||
		typs->path_so == NULL)
		return (1);
	return (0);
}

int				mapchecktwo(t_settings *set, int amount)
{
	int			i;
	int			j;

	i = 0;
	while (++i < amount)
	{
		j = -1;
		while (++j < (int)(ft_strlen(set->map[i])))
		{
			if (set->map[i][j] == '0' || set->map[i][j] == '2' ||
				set->map[i][j] == 'N' || set->map[i][j] == 'S' ||
				set->map[i][j] == 'W' || set->map[i][j] == 'E')
			{
				if ((int)(ft_strlen(set->map[i - 1])) < j ||
					(int)(ft_strlen(set->map[i + 1])) < j)
					return (1);
				if (set->map[i - 1][j] == ' ' || set->map[i - 1][j] == '\0' ||
					set->map[i + 1][j] == ' ' || set->map[i + 1][j] == '\0' ||
					set->map[i][j - 1] == ' ' || set->map[i][j - 1] == '\0' ||
					set->map[i][j + 1] == ' ' || set->map[i][j + 1] == '\0')
					return (1);
			}
		}
	}
	return (0);
}

int				checklast(t_settings *set, int amount)
{
	int	j;

	j = 0;
	while (j < (int)(ft_strlen(set->map[0])))
	{
		if (set->map[0][j] != '1' && set->map[0][j] != ' ')
			return (1);
		j++;
	}
	j = 0;
	while (j < (int)(ft_strlen(set->map[amount])))
	{
		if (set->map[amount][j] != '1' &&
			set->map[amount][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

int				mapcheck(t_settings *set, int amount)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	while (i < amount)
	{
		j = -1;
		while (++j < (int)(ft_strlen(set->map[i])))
			if (set->map[i][j] != '1' && set->map[i][j] != ' ' &&
				set->map[i][j] != '0' && set->map[i][j] != '2')
			{
				if (!ft_strchr("NWES", set->map[i][j]) || k > 0)
					return (1);
				else
					k++;
			}
		i++;
	}
	if (k == 0)
		errmsg("Many persons");
	return (checklast(set, amount));
}

int				mapvertcheck(t_settings *set)
{
	int			i;

	i = 0;
	while (i < set->amnt)
	{
		if (set->map[i][0] != '1' && set->map[i][0] != ' ')
			return (1);
		i++;
	}
	return (0);
}
