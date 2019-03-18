/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:29:29 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/18 07:18:32 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_mlx *mlx, t_point *point)
{
	if (point->z == 0 && point->z1 == 0)
		line(mlx, point, 0x00ff00);
	else if (point->z == point->z1)
		line(mlx, point, 0x88ffff);
	else
		line(mlx, point, 0xff0000);
}

void	print_lineyello(t_mlx *mlx, t_point *point)
{
	if (point->z == 0 && point->z1 == 0)
		line(mlx, point, 0x00ff00);
	else if (point->z == point->z1)
		line(mlx, point, 0x88ffff);
	else
		line(mlx, point, 0xffff00);
}

void	fdf(t_mlx *mlx)
{
	t_truc	coefij;
	t_point	point;

	coefij.coef1 = mlx->largeur / (mlx->line * 2);
	coefij.coef2 = mlx->hauteur / (mlx->col * 2);
	coefij.i = 0;
	while (coefij.i < mlx->line)
	{
		coefij.j = 0;
		while (coefij.j < mlx->col)
		{
			get_x_y(mlx, &point, &coefij);
			if (coefij.i < (mlx->line - 1) && coefij.j < (mlx->col - 1))
			{
				get_nextx(mlx, &point, &coefij);
				print_line(mlx, &point);
				get_nexty(mlx, &point, &coefij);
				print_lineyello(mlx, &point);
			}
			coefij.j++;
		}
		coefij.i++;
	}
}
