/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 12:26:06 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/18 23:32:59 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	clean_window(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while(i < mlx->largeur)
	{
		j = 0;
		while (j < mlx->hauteur)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
					i, j, 0x000000);
			j++;
		}
		i++;
	}
}

static void	incr(int keycode, t_mlx *mlx)
{
	if (keycode == 69)
		mlx->yolo++;
	if (keycode == 78)
		mlx->yolo--;
	write(1, ft_itoa(mlx->yolo), 2);
}

static void	change_proj(t_mlx *mlx)
{
	if (mlx->proj == 0)
		mlx->proj = 1;
	else if (mlx->proj == 1)
		mlx->proj = 0;
}

int		ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 78)
		incr(keycode, mlx);
	if (keycode == 35)
		change_proj(mlx);
	clean_window(mlx);
	fdf(mlx);
	return (0);
}
