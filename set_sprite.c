/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:06:31 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/18 19:06:34 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		setsprdist(t_settings *set)
{
	int		i;

	i = 0;
	while (i < set->spsum)
	{
		set->sprordr[i] = i;
		set->sprdst[i] = ((set->posx - set->sp[i].x) * (set->posx -
		set->sp[i].x) + (set->posy - set->sp[i].y) *
												(set->posy - set->sp[i].y));
		i++;
	}
}

void		set_spxyd(t_settings *set, int x, int y, int i)
{
	set->sp[i].x = x + 0.5;
	set->sp[i].y = y + 0.5;
	set->sp[i].dst = 0.0;
}

void		set_sprite(t_settings *set)
{
	int		nc;
	int		i;
	int		j;

	nc = 0;
	i = 0;
	while (set->map[i])
	{
		j = 0;
		while (set->map[i][j])
		{
			if (set->map[i][j] == '2')
			{
				set_spxyd(set, i, j, nc);
				nc++;
			}
			j++;
		}
		i++;
	}
}

void		find_sp(t_settings *set)
{
	int		i;
	int		j;

	i = 0;
	while (set->map[i])
	{
		j = 0;
		while (set->map[i][j])
		{
			if (set->map[i][j] == '2')
				set->spsum++;
			j++;
		}
		i++;
	}
	if (!(set->sp = malloc(set->spsum * sizeof(t_spr))) ||
	!(set->sprdst = (double *)malloc(sizeof(double ) * set->spsum)) ||
	!(set->sprordr = (int *)malloc(sizeof(int) * set->spsum)))
		errmsg("Malloc return NULL");
	set_sprite(set);
}
