/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:46:04 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/17 15:43:47 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>


void iso(int *x, int *y, int z)
{
	int previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	fdf(t_mlx *mlx)
{
	int coef1 = mlx->Largeur / (mlx->line * 2);
	int coef2 = mlx->Hauteur / (mlx->col * 2);
	int i;
	int j;
	t_point	point;

	i = 0;
	while(i < mlx->line)
	{
		j = 0;
		while(j < mlx->col)
		{
			point.y = (coef1 * i) + 125;
			point.x = (coef2 * j) + 300;
			point.z = (15 * mlx->board[i][j]);
			iso(&point.x, &point.y, point.z);
			if (i < (mlx->line - 1) && j < (mlx->col - 1))
			{
				point.y1 = (coef1 * (i + 1)) + 125;
				point.x1 = (coef2 * j) + 300;
				point.z1 = (15 * mlx->board[i + 1][j]);
				iso(&point.x1, &point.y1, point.z1);
				if (point.z == 0 && point.z1 == 0)
					line(mlx, &point, 0x00ff00);
				else if ( point.z == point.z1)
					line(mlx, &point, 0x88ffff);
				else
					line(mlx, &point, 0xff0000);
				point.y1 = (coef1 * i) + 125;
				point.x1 = (coef2 * (j + 1)) + 300;
				point.z1 = (15 * mlx->board[i][j + 1]);
				iso(&point.x1, &point.y1, point.z1);
				if (point.z == 0 && point.z1 == 0)	
					line(mlx, &point, 0x00ff00);
				else if (point.z == point.z1)
					line(mlx, &point, 0x88ffff);
				else
					line(mlx, &point, 0xffff00);
			}
			j++;
		}
		i++;
	}
}

void	launch_graphic(int **board, int line, int col)
{
	t_mlx	mlx;

	mlx.line = line;
	mlx.col = col;
	mlx.board = board;
	mlx.Hauteur = HAUTEUR;
	mlx.Largeur = LARGEUR;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, LARGEUR, HAUTEUR, "SALUT");
	fdf(&mlx);
	mlx_key_hook(mlx.win_ptr, ft_key_hook, (void *)0);
	mlx_loop(mlx.mlx_ptr);
}

int		main(int argc, char **argv)
{
	int fd;
	int **board;
	t_check	check;

	check.check = 1;
	if (basic_check(argc, argv) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	board = parsing(fd, argv, &check);
	if (check.check == -1)
	{
		write (1, "parsing failed : file is not same number of collumns", 52);
		return (-1);
	}
	launch_graphic(board, check.line, check.col);
	close(fd);
}
