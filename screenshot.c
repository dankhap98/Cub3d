/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:42:27 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/21 20:42:30 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_screen(t_settings *set, int fd)
{
	int		size_screen;
	int		pos_pixel_data;
	int		zero;
	short	plane;

	plane = 1;
	zero = 0;
	pos_pixel_data = 54;
	size_screen = set->resx * set->resy * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pixel_data, 4);
	pos_pixel_data = 40;
	write(fd, &pos_pixel_data, 4);
	write(fd, &set->resx, 4);
	write(fd, &set->resy, 4);
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

static void	filling_file_screen(t_settings *set, int fd)
{
	int	i;
	int	j;
	int	color;

	i = set->resy;
	while (--i >= 0)
	{
		j = -1;
		while (++j < set->resx)
		{
			color = *(int*)(set->img.addr + (i * set->img.line_l
										+ j * (set->img.bits_per_pixel / 8)));
			write(fd, &color, 4);
		}
	}
}

void		screenshot(t_settings *set)
{
	int fd;
	int size_screen;
	int zero;
	int size;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)) < 0)
		errmsg("screenshot");
	size_screen = set->resx * set->resy * 4 + 54;
	zero = 0;
	size = set->resx * set->resy;
	create_screen(set, fd);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	size_screen = 1000;
	write(fd, &size_screen, 4);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	filling_file_screen(set, fd);
	close(fd);
}
