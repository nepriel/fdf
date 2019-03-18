/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:24:25 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/17 16:35:54 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	get_x_y(t_mlx *mlx, t_point *point, t_truc *coefij)
{
	point->y = (coefij->coef1 * coefij->i) + 0;
	point->x = (coefij->coef2 * coefij->j) + 300;
	point->z = (15 * mlx->board[coefij->i][coefij->j]);
	iso(&point->x, &point->y, point->z);
}

void	get_nextx(t_mlx *mlx, t_point *point, t_truc *coefij)
{
	point->y1 = (coefij->coef1 * (coefij->i + 1)) + 0;
	point->x1 = (coefij->coef2 * coefij->j) + 300;
	point->z1 = (15 * mlx->board[coefij->i + 1][coefij->j]);
	iso(&point->x1, &point->y1, point->z1);
}

void	get_nexty(t_mlx *mlx, t_point *point, t_truc *coefij)
{
	point->y1 = (coefij->coef1 * coefij->i) + 0;
	point->x1 = (coefij->coef2 * (coefij->j + 1)) + 300;
	point->z1 = (15 * mlx->board[coefij->i][coefij->j + 1]);
	iso(&point->x1, &point->y1, point->z1);
}
