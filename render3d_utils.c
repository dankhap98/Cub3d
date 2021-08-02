/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:06:14 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/21 22:06:17 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			drawnoso(t_settings *set, int x, t_one *mms)
{
	int			y;

	y = set->drawstart;
	if (set->stepx > 0)
	{
		while (y++ <= set->draw_end)
		{
			set->tx_y = (int)mms->txpos & (64 - 1);
			mms->txpos += set->step;
			set->color = set->texture[2][64 * set->tx_y + set->tx_x];
			my_mlx_pixel_put(set, x, y, set->color);
		}
	}
	else
	{
		while (y++ <= set->draw_end)
		{
			set->tx_y = (int)mms->txpos & (64 - 1);
			mms->txpos += set->step;
			set->color = set->texture[1][64 * set->tx_y + set->tx_x];
			my_mlx_pixel_put(set, x, y, set->color);
		}
	}
}

void			drawweea(t_settings *set, int x, t_one *mms)
{
	int			y;

	y = set->drawstart;
	if (set->stepy > 0)
	{
		while (y++ <= set->draw_end)
		{
			set->tx_y = (int)mms->txpos & (64 - 1);
			mms->txpos += set->step;
			set->color = set->texture[4][64 * set->tx_y + set->tx_x];
			my_mlx_pixel_put(set, x, y, set->color);
		}
	}
	else
	{
		while (y++ <= set->draw_end)
		{
			set->tx_y = (int)mms->txpos & (64 - 1);
			mms->txpos += set->step;
			set->color = set->texture[3][64 * set->tx_y + set->tx_x];
			my_mlx_pixel_put(set, x, y, set->color);
		}
	}
}

void			setstep(t_settings *set, int mapx, int mapy)
{
	if (set->raydirx < 0)
	{
		set->stepx = -1;
		set->sidedistx = (set->posx - mapx) * set->deltadistx;
	}
	else
	{
		set->stepx = 1;
		set->sidedistx = (mapx + 1.0 - set->posx) * set->deltadistx;
	}
	if (set->raydiry < 0)
	{
		set->stepy = -1;
		set->sidedisty = (set->posy - mapy) * set->deltadisty;
	}
	else
	{
		set->stepy = 1;
		set->sidedisty = (mapy + 1.0 - set->posy) * set->deltadisty;
	}
}

void			dda(t_settings *set, t_one *mms)
{
	int			hit;

	hit = 0;
	while (hit == 0)
	{
		if (set->sidedistx < set->sidedisty)
		{
			set->sidedistx += set->deltadistx;
			mms->mapx += set->stepx;
			mms->side = 0;
		}
		else
		{
			set->sidedisty += set->deltadisty;
			mms->mapy += set->stepy;
			mms->side = 1;
		}
		if (set->map[mms->mapx][mms->mapy] == '1')
		{
			hit++;
		}
	}
}

void			side(t_settings *set, t_one *mms)
{
	(mms->side == 0) ? (set->perpwalldist = (mms->mapx - set->posx
									+ (1 - set->stepx) / 2) / set->raydirx) : 0;
	(mms->side == 0) ? 0 : (set->perpwalldist = (mms->mapy - set->posy
										+ (1 - set->stepy) / 2) / set->raydiry);
	set->line_height = (int)(set->resy / set->perpwalldist);
	set->drawstart = -set->line_height / 2 + set->resy / 2;
	(set->drawstart < 0) ? (set->drawstart = 0) : 0;
	set->draw_end = set->line_height / 2 + set->resy / 2;
	(set->draw_end >= set->resy) ? (set->draw_end = set->resy - 1) : 0;
	if (mms->side == 0)
		set->wallx = set->posy + set->perpwalldist * set->raydiry;
	else
		(set->wallx = set->posx + set->perpwalldist * set->raydirx);
	set->wallx -= floor((set->wallx));
	set->tx_x = (int)(set->wallx * (double)(64));
	(mms->side == 0 && set->raydirx > 0) ? (set->tx_x = (64)
														- set->tx_x - 1) : 0;
	(mms->side == 1 && set->raydiry < 0) ? (set->tx_x = (64)
														- set->tx_x - 1) : 0;
	set->step = 1.0 * 64 / set->line_height;
	mms->txpos = (set->drawstart - set->resy / 2 + set->line_height / 2) *
																	set->step;
}
