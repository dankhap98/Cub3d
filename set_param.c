/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:21:26 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/07 14:21:32 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_window(t_settings *set, char *val)
{
	char	**xy;
	int		maxwight;
	int		maxheight;

	(set->resx != 0 || set->resy != 0) ? errmsg("uncorrect res") : 0;
	mlx_get_screen_size(&maxwight, &maxheight);
	xy = ft_split(val, ' ');
	if (xy[2])
		errmsg("uncorrect resolution!");
	intres(xy);
	restomax(set, xy);
	if (set->save != 1)
	{
		if (set->resx > maxwight)
			set->resx = maxwight;
		if (set->resy > maxheight)
			set->resy = maxheight;
	}
	freetwomas(xy);
}

void	set_texture(t_settings *set, char *val, int c)
{
	if (c == 1 && !(set->path_no))
		set->path_no = ft_strdup(val);
	else if (c == 2 && !(set->path_so))
		set->path_so = ft_strdup(val);
	else if (c == 3 && !(set->path_we))
		set->path_we = ft_strdup(val);
	else if (c == 4 && !(set->path_ea))
		set->path_ea = ft_strdup(val);
	else if (c == 5 && !(set->pth_sp))
		set->pth_sp = ft_strdup(val);
	else
		errmsg("Invalid in tex");
}

void	checkcolormas(char **rgb)
{
	int		i;
	int		j;

	i = 0;
	if (rgb[3])
		errmsg("Error, uncorrect color!");
	while (rgb[i])
	{
		chkspace2(rgb[i]);
		j = 0;
		while (rgb[i][j])
		{
			if (!(ft_isdigit(rgb[i][j])) && rgb[i][j] != ' ')
				errmsg("Error, uncorrect color!");
			j++;
		}
		i++;
	}
}

void	chek_colormas2(t_settings *set, int c)
{
	if (c == 1)
	{
		if (set->f_color[0] != -1 || set->f_color[1] != -1 ||
				set->f_color[2] != -1)
			errmsg("Error, uncorrect color!");
	}
	if (c == 2)
	{
		if (set->c_color[0] != -1 || set->c_color[1] != -1 ||
			set->c_color[2] != -1)
			errmsg("Error, uncorrect color!");
	}
}

void	set_color(t_settings *set, char *val, int c)
{
	char	**rgb;

	rgb = ft_split(val, ',');
	checkcolormas(rgb);
	checkcomma(rgb, val);
	intcolor(rgb);
	if (c == 1)
	{
		chek_colormas2(set, c);
		set->f_color[0] = ft_atoi(rgb[0]);
		set->f_color[1] = ft_atoi(rgb[1]);
		set->f_color[2] = ft_atoi(rgb[2]);
	}
	if (c == 2)
	{
		chek_colormas2(set, c);
		set->c_color[0] = ft_atoi(rgb[0]);
		set->c_color[1] = ft_atoi(rgb[1]);
		set->c_color[2] = ft_atoi(rgb[2]);
	}
	freetwomas(rgb);
}
