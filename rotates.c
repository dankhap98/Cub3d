/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:53:32 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/21 21:53:34 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			rot_left(t_settings *set)
{
	double olddirx;
	double oldplanex;

	olddirx = set->dirx;
	set->dirx = set->dirx * cos(-ROTSPD) - set->diry * sin(-ROTSPD);
	set->diry = olddirx * sin(-ROTSPD) + set->diry * cos(-ROTSPD);
	oldplanex = set->planex;
	set->planex = set->planex * cos(-ROTSPD) - set->planey * sin(-ROTSPD);
	set->planey = oldplanex * sin(-ROTSPD) + set->planey * cos(-ROTSPD);
}

void			rot_right(t_settings *set)
{
	double olddirx;
	double oldplanex;

	olddirx = set->dirx;
	set->dirx = set->dirx * cos(ROTSPD) - set->diry * sin(ROTSPD);
	set->diry = olddirx * sin(ROTSPD) + set->diry * cos(ROTSPD);
	oldplanex = set->planex;
	set->planex = set->planex * cos(ROTSPD) - set->planey * sin(ROTSPD);
	set->planey = oldplanex * sin(ROTSPD) + set->planey * cos(ROTSPD);
}

void			move(t_settings *set)
{
	if (set->move.forv == 1)
		move_forvard(set);
	if (set->move.back == 1)
		move_back(set);
	if (set->move.left == 1)
		move_left(set);
	if (set->move.rhight == 1)
		move_right(set);
	if (set->move.rotlef == 1)
		rot_left(set);
	if (set->move.rotrh == 1)
		rot_right(set);
}

int				key_release(int keycode, t_settings *set)
{
	if (keycode == 13)
		set->move.forv = 0;
	if (keycode == 1)
		set->move.back = 0;
	if (keycode == 0)
		set->move.left = 0;
	if (keycode == 2)
		set->move.rhight = 0;
	if (keycode == 124)
		set->move.rotlef = 0;
	if (keycode == 123)
		set->move.rotrh = 0;
	return (0);
}
