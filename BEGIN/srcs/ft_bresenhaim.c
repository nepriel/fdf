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
	erreur = pt_brese->Dy / 2;
	i = 0;
	while (i < pt_brese->Dy)
	{
		pt_brese->y += pt_brese->yincr;
		erreur += pt_brese->Dx;
		if (erreur > pt_brese->Dy)
		{
			erreur -= pt_brese->Dy;
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
	erreur = pt_brese->Dx / 2;
	i = 0;
	while (i < pt_brese->Dx)
	{
		pt_brese->x += pt_brese->xincr;
		erreur += pt_brese->Dy;
		if (erreur > pt_brese->Dx)
		{
			erreur -= pt_brese->Dx;
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
	pt_brese.Dx = abs(pt_brese.x2 - pt_brese.x1);
	pt_brese.Dy = abs(pt_brese.y2 - pt_brese.y1);
	if (pt_brese.x1 < pt_brese.x2)
		pt_brese.xincr = 1;
	else
		pt_brese.xincr = -1;
	if (pt_brese.y1 < pt_brese.y2)
		pt_brese.yincr = 1;
	else
		pt_brese.yincr = -1;
	if (pt_brese.Dx > pt_brese.Dy)
		dxbigger(mlx, couleur, &pt_brese);
	else
		dxsmaller(mlx, couleur, &pt_brese);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
			pt_brese.x1, pt_brese.y1, couleur);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
			pt_brese.x2, pt_brese.y2, couleur);
}
