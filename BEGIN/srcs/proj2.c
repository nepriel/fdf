/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:42:40 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/19 15:30:37 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	proj2(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = *x - z;
	*y = *y - z;
}

void	get_x_y2(t_mlx *mlx, t_point *point, t_truc *coefij)
{
	point->y = (coefij->coef1 * coefij->i) + 125;
	point->x = (coefij->coef2 * coefij->j) + 125;
	point->z = ((5 * mlx->yolo) * mlx->board[coefij->i][coefij->j]);
	proj2(&point->x, &point->y, point->z);
}

void	get_nextx2(t_mlx *mlx, t_point *point, t_truc *coefij)
{
	point->y1 = (coefij->coef1 * (coefij->i + 1)) + 125;
	point->x1 = (coefij->coef2 * coefij->j) + 125;
	point->z1 = ((5 * mlx->yolo) * mlx->board[coefij->i + 1][coefij->j]);
	proj2(&point->x1, &point->y1, point->z1);
}

void	get_nexty2(t_mlx *mlx, t_point *point, t_truc *coefij)
{
	point->y1 = (coefij->coef1 * coefij->i) + 125;
	point->x1 = (coefij->coef2 * (coefij->j + 1)) + 125;
	point->z1 = ((5 * mlx->yolo) * mlx->board[coefij->i][coefij->j + 1]);
	proj2(&point->x1, &point->y1, point->z1);
}
