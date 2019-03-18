/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenhaim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 10:23:41 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/17 11:00:06 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dxsmaller(t_mlx *mlx, int couleur, t_ptbrese *pt_brese)
{
	int erreur;
	int i;

	pt_brese->x = pt_brese->x1;
	pt_brese->y = pt_brese->y1;
	erreur = pt_brese->dy / 2;
	i = 0;
	while (i < pt_brese->dy)
	{
		pt_brese->y += pt_brese->yincr;
		erreur += pt_brese->dx;
		if (erreur > pt_brese->dy)
		{
			erreur -= pt_brese->dy;
			pt_brese->x += pt_brese->xincr;
		}
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
				pt_brese->x, pt_brese->y, couleur);
		i++;
	}
}

void	dxbigger(t_mlx *mlx, int couleur, t_ptbrese *pt_brese)
{
	int erreur;
	int i;

	pt_brese->x = pt_brese->x1;
	pt_brese->y = pt_brese->y1;
	erreur = pt_brese->dx / 2;
	i = 0;
	while (i < pt_brese->dx)
	{
		pt_brese->x += pt_brese->xincr;
		erreur += pt_brese->dy;
		if (erreur > pt_brese->dx)
		{
			erreur -= pt_brese->dx;
			pt_brese->y += pt_brese->yincr;
		}
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
				pt_brese->x, pt_brese->y, couleur);
		i++;
	}
}

void	line(t_mlx *mlx, t_point *point, int couleur)
{
	t_ptbrese	pt_brese;

	pt_brese.x1 = point->x;
	pt_brese.x2 = point->x1;
	pt_brese.y1 = point->y;
	pt_brese.y2 = point->y1;
	pt_brese.dx = abs(pt_brese.x2 - pt_brese.x1);
	pt_brese.dy = abs(pt_brese.y2 - pt_brese.y1);
	if (pt_brese.x1 < pt_brese.x2)
		pt_brese.xincr = 1;
	else
		pt_brese.xincr = -1;
	if (pt_brese.y1 < pt_brese.y2)
		pt_brese.yincr = 1;
	else
		pt_brese.yincr = -1;
	if (pt_brese.dx > pt_brese.dy)
		dxbigger(mlx, couleur, &pt_brese);
	else
		dxsmaller(mlx, couleur, &pt_brese);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
			pt_brese.x1, pt_brese.y1, couleur);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
			pt_brese.x2, pt_brese.y2, couleur);
}
