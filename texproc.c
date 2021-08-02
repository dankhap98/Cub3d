/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texproc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:52:49 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/16 13:53:16 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkimgres(int w, int h)
{
	if (h != 64 || w != 64)
		errmsg("invalid image resolution!");
}

void	inittex(t_settings *set)
{
	int		i;
	int		j;

	i = 0;
	if (!(set->texture = (int **)malloc(sizeof(int *) * 6)))
		errmsg("Malloc error!");
	while (i++ < 5)
	{
		if (!(set->texture[i] = (int *)malloc(sizeof(int) * (4096))))
			errmsg("Malloc error!");
	}
	i = 0;
	while (i++ < 5)
	{
		j = 0;
		while (j++ < 4096)
			set->texture[i][j] = 0;
	}
}

void	loadtex(t_settings *set)
{
	xpmntoimg(set, 1, set->path_no);
	xpmstoimg(set, 2, set->path_so);
	xpmwtoimg(set, 3, set->path_we);
	xpmetoimg(set, 4, set->path_ea);
	xpmsptoimg(set, 5, set->pth_sp);
}
