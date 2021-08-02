/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:49:54 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/18 19:49:56 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			sort_order(t_pair *orders, int amount)
{
	t_pair		tmp;
	int			i;
	int			j;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void			sortsprites(int *order, double *dist, int amount)
{
	t_pair		*pair;
	int			i;

	i = 0;
	if (!(pair = (t_pair*)malloc(sizeof(t_pair) * amount)))
		errmsg("Malloc return NULL");
	while (i < amount)
	{
		pair[i].first = dist[i];
		pair[i].second = order[i];
		i++;
	}
	i = 0;
	sort_order(pair, amount);
	while (i < amount)
	{
		dist[i] = pair[amount - i - 1].first;
		order[i] = pair[amount - i - 1].second;
		i++;
	}
	free(pair);
}

void			rend_sprite(t_settings *set, t_spdata *spdt, double *zbuf)
{
	int			stripe;
	int			y;
	int			d;

	stripe = spdt->drawstart_x;
	while (stripe < spdt->drawend_x)
	{
		spdt->tex_x = (int)(256 * (stripe - (-spdt->sprtwhigt / 2 +
				spdt->sprscrn_x)) * 64 / spdt->sprtwhigt) / 256;
		if (spdt->transf_y > 0 && stripe >= 0 && stripe < set->resx &&
		spdt->transf_y < zbuf[stripe])
		{
			y = spdt->drawstart_y;
			while (y < spdt->drawend_y)
			{
				d = y * 256 - set->resy * 128 + spdt->sprtheight * 128;
				spdt->tex_y = ((d * 63) / spdt->sprtheight) / 256;
				spdt->color = set->texture[5][64 * spdt->tex_y + spdt->tex_x];
				if ((spdt->color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(set, stripe, y, spdt->color);
				y++;
			}
		}
		stripe++;
	}
}

void			sprite_math(t_settings *set, t_spdata *spdt, int i)
{
	spdt->sprt_x = set->sp[set->sprordr[i]].x - set->posx;
	spdt->sprt_y = set->sp[set->sprordr[i]].y - set->posy;
	spdt->indet = 1.0 / (set->planex * set->diry - set->dirx * set->planey);
	spdt->transf_x = spdt->indet * (set->diry
									* spdt->sprt_x - set->dirx * spdt->sprt_y);
	spdt->transf_y = spdt->indet * (-set->planey
								* spdt->sprt_x + set->planex * spdt->sprt_y);
	spdt->sprscrn_x = (int)((set->resx / 2)
							* (1 + spdt->transf_x / spdt->transf_y));
	spdt->sprtheight = (int)(fabs((set->resy / (spdt->transf_y))));
	spdt->drawstart_y = -spdt->sprtheight / 2 + set->resy / 2;
	(spdt->drawstart_y < 0) ? (spdt->drawstart_y = 0) : 0;
	spdt->drawend_y = spdt->sprtheight / 2 + set->resy / 2;
	(spdt->drawend_y >= set->resy) ?
	(spdt->drawend_y = set->resy - 1) : 0;
	spdt->sprtwhigt = (int)(fabs((set->resy / (spdt->transf_y))) - 1);
	spdt->drawstart_x = -spdt->sprtwhigt / 2 + spdt->sprscrn_x;
	(spdt->drawstart_x < 0) ? (spdt->drawstart_x = 0) : 0;
	spdt->drawend_x = spdt->sprtwhigt / 2 + spdt->sprscrn_x;
	(spdt->drawend_x >= set->resx) ?
	(spdt->drawend_x = set->resx - 1) : 0;
}

void			drawsp(t_settings *set, double *zbuf)
{
	t_spdata	*spdt;
	int			i;

	i = 0;
	if (!(spdt = (t_spdata *)malloc(sizeof(t_spdata))))
		errmsg("Malloc return NULL");
	setsprdist(set);
	sortsprites(set->sprordr, set->sprdst, set->spsum);
	while (i < set->spsum)
	{
		sprite_math(set, spdt, i);
		rend_sprite(set, spdt, zbuf);
		i++;
	}
	free(spdt);
}
