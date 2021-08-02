/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moovement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:51:48 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/21 21:51:51 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			move_forvard(t_settings *set)
{
	if (set->map[(int)(set->posx + set->dirx * MOVESPD)][(int)(set->posy +
												set->diry * MOVESPD)] != '1')
	{
		set->posx += set->dirx * MOVESPD;
		set->posy += set->diry * MOVESPD;
	}
}

void			move_back(t_settings *set)
{
	if (set->map[(int)(set->posx - set->dirx * MOVESPD)][(int)(set->posy -
												set->diry * MOVESPD)] != '1')
	{
		set->posx -= set->dirx * MOVESPD;
		set->posy -= set->diry * MOVESPD;
	}
}

void			move_left(t_settings *set)
{
	if (set->map[(int)(set->posx - set->diry * MOVESPD)][(int)(set->posy +
												set->dirx * MOVESPD)] != '1')
	{
		set->posx -= set->diry * MOVESPD;
		set->posy += set->dirx * MOVESPD;
	}
}

void			move_right(t_settings *set)
{
	if (set->map[(int)(set->posx + set->diry * MOVESPD)][(int)(set->posy -
												set->dirx * MOVESPD)] != '1')
	{
		set->posx += set->diry * MOVESPD;
		set->posy -= set->dirx * MOVESPD;
	}
}
