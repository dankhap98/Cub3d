/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmng.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:09:10 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/21 16:09:12 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		errmsg(char *ertx)
{
	ft_putendl_fd("Error", 1);
	ft_putstr_fd(ertx, 1);
	exit(1);
}

void		checkcomma(char **rgb, char *val)
{
	int		lenv;
	int		lenrgb;
	int		count;

	lenv = ft_strlen(val);
	lenrgb = 0;
	count = 0;
	while (rgb[count])
	{
		lenrgb += ft_strlen(rgb[count]);
		count++;
	}
	lenrgb = lenrgb + 2;
	if (lenv != lenrgb || count != 3)
		errmsg("color");
}

void		chkspace2(char *rgb)
{
	int		i;
	int		ch;

	i = 0;
	ch = 0;
	while (rgb[i])
	{
		if (rgb[i] != ' ')
			ch++;
		i++;
	}
	if (ch == 0)
		errmsg("spaces");
}

void		chkspace(char *rgb)
{
	int		i;
	int		ch;

	i = 2;
	ch = 0;
	while (rgb[i])
	{
		if (rgb[i] != ' ')
			ch++;
		i++;
	}
	if (ch == 0)
		errmsg("spaces");
}

void		chkerr(t_settings *set)
{
	set->er += checkparams(set) + mapcheck(set, set->amnt) + mapvertcheck(set);
	if (set->er > 0)
		errmsg("Error, ivalid configuration");
	if (mapchecktwo(set, set->amnt))
		errmsg("Error, ivalid configuration");
}
