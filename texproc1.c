/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texproc1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:39:53 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/21 21:39:55 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpmntoimg(t_settings *set, int i, char *path)
{
	int		x;
	int		y;

	y = -1;
	if (!(set->n_txdt.img = mlx_new_image(set->mlx, 64, 64)))
		errmsg("Error teximg");
	if (!(set->n_txdt.img = mlx_xpm_file_to_image(set->mlx, path,
										&set->n_txdt.t_w, &set->n_txdt.t_h)))
		errmsg("Error teximg");
	checkimgres(set->n_txdt.t_w, set->n_txdt.t_h);
	set->n_txdt.addr = (int *)mlx_get_data_addr(set->n_txdt.img,
		&set->n_txdt.bits_per_pixel, &set->n_txdt.line_l, &set->n_txdt.endian);
	while (++y < set->n_txdt.t_h)
	{
		x = -1;
		while (++x < set->n_txdt.t_w)
			set->texture[i][set->n_txdt.t_w * y + x] =
					set->n_txdt.addr[set->n_txdt.t_w * y + x];
	}
	mlx_destroy_image(set->mlx, set->n_txdt.img);
}

void	xpmstoimg(t_settings *set, int i, char *path)
{
	int		x;
	int		y;

	y = -1;
	if (!(set->s_txdt.img = mlx_new_image(set->mlx, 64, 64)))
		errmsg("Error teximg");
	if (!(set->s_txdt.img = mlx_xpm_file_to_image(set->mlx, path,
										&set->s_txdt.t_w, &set->s_txdt.t_h)))
		errmsg("Error teximg");
	checkimgres(set->s_txdt.t_w, set->s_txdt.t_h);
	set->s_txdt.addr = (int *)mlx_get_data_addr(set->s_txdt.img,
		&set->s_txdt.bits_per_pixel, &set->s_txdt.line_l, &set->s_txdt.endian);
	while (++y < set->s_txdt.t_h)
	{
		x = 0;
		while (x++ < set->s_txdt.t_w)
			set->texture[i][set->s_txdt.t_w * y + x] =
					set->s_txdt.addr[set->s_txdt.t_w * y + x];
	}
	mlx_destroy_image(set->mlx, set->s_txdt.img);
}

void	xpmwtoimg(t_settings *set, int i, char *path)
{
	int		x;
	int		y;

	y = -1;
	if (!(set->w_txdt.img = mlx_new_image(set->mlx, 64, 64)))
		errmsg("Error teximg");
	if (!(set->w_txdt.img = mlx_xpm_file_to_image(set->mlx, path,
										&set->w_txdt.t_w, &set->w_txdt.t_h)))
		errmsg("Error teximg");
	checkimgres(set->w_txdt.t_w, set->w_txdt.t_h);
	set->w_txdt.addr = (int *)mlx_get_data_addr(set->w_txdt.img,
		&set->w_txdt.bits_per_pixel, &set->w_txdt.line_l, &set->w_txdt.endian);
	while (++y < set->w_txdt.t_h)
	{
		x = 0;
		while (x++ < set->w_txdt.t_w)
			set->texture[i][set->w_txdt.t_w * y + x] =
					set->w_txdt.addr[set->w_txdt.t_w * y + x];
	}
	mlx_destroy_image(set->mlx, set->w_txdt.img);
}

void	xpmetoimg(t_settings *set, int i, char *path)
{
	int		x;
	int		y;

	y = -1;
	if (!(set->e_txdt.img = mlx_new_image(set->mlx, 64, 64)))
		errmsg("Error teximg");
	if (!(set->e_txdt.img = mlx_xpm_file_to_image(set->mlx, path,
										&set->e_txdt.t_w, &set->e_txdt.t_h)))
		errmsg("Error teximg");
	checkimgres(set->e_txdt.t_w, set->e_txdt.t_h);
	set->e_txdt.addr = (int *)mlx_get_data_addr(set->e_txdt.img,
		&set->e_txdt.bits_per_pixel, &set->e_txdt.line_l, &set->e_txdt.endian);
	while (++y < set->e_txdt.t_h)
	{
		x = 0;
		while (x++ < set->e_txdt.t_w)
			set->texture[i][set->e_txdt.t_w * y + x] =
					set->e_txdt.addr[set->e_txdt.t_w * y + x];
	}
	mlx_destroy_image(set->mlx, set->e_txdt.img);
}

void	xpmsptoimg(t_settings *set, int i, char *path)
{
	int		x;
	int		y;

	y = -1;
	if (!(set->sp_tx.img = mlx_new_image(set->mlx, 64, 64)))
		errmsg("Error teximg");
	if (!(set->sp_tx.img = mlx_xpm_file_to_image(set->mlx, path,
											&set->sp_tx.t_w, &set->sp_tx.t_h)))
		errmsg("Error teximg");
	checkimgres(set->sp_tx.t_w, set->sp_tx.t_h);
	set->sp_tx.addr = (int *)mlx_get_data_addr(set->sp_tx.img,
		&set->sp_tx.bits_per_pixel, &set->sp_tx.line_l, &set->sp_tx.endian);
	while (++y < set->sp_tx.t_h)
	{
		x = 0;
		while (x++ < set->sp_tx.t_w)
			set->texture[i][set->sp_tx.t_w * y + x] =
					set->sp_tx.addr[set->sp_tx.t_w * y + x];
	}
	mlx_destroy_image(set->mlx, set->sp_tx.img);
}
