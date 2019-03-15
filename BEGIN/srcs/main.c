/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:46:04 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/15 17:05:05 by vlhomme          ###   ########.fr       */
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

void	fdf(void *mlx_ptr, void *win_ptr, int line, int col, int largeur, int hauteur, int **board)
{
	int coef1 = largeur / (line * 2);
	int coef2 = hauteur / (col * 2);
	int i;
	int j;
	int x;
	int y;
	int z;
	int x1;
	int y1;
	int z1;
	int x2;
	int y2;
	int z2;

	i = 0;
	while(i < line)
	{
		j = 0;
		while(j < col)
		{
			y = (coef1 * i) + 125;
			x = (coef2 * j) + 300;
			z = (15 * board[i][j]);
			iso(&x, &y, z);
			if (i < (line - 1) && j < (col - 1))
			{
				y1 = (coef1 * (i + 1)) + 125;
				x1 = (coef2 * j) + 300;
				z1 = (15 * board[i + 1][j]);
				iso(&x1, &y1, z1);
				if (z == 0 && z1 == 0)
					Line(mlx_ptr, win_ptr, x, y, x1, y1, 0x00ff00);
				else
					Line(mlx_ptr, win_ptr, x, y, x1, y1, 0xff0000);
				y2 = (coef1 * i) + 125;
				x2 = (coef2 * (j + 1)) + 300;
				z2 = (15 * board[i][j + 1]);
				iso(&x2, &y2, z2);
				if (z == 0 && z2 == 0)	
					Line(mlx_ptr, win_ptr, x, y, x2, y2, 0x00ff00);
				else
					Line(mlx_ptr, win_ptr, x, y, x2, y2, 0xffff00);
				//mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xffffff);
			}
			//mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
			j++;
		}
		i++;
	}
	//Line(mlx_ptr, win_ptr, 0, 0, 500, 500, 0x00ff00);
}

void	launch_graphic(int **board, int line, int col)
{
	void	*mlx_ptr;
	void	*win_ptr;

	(void)line;
	(void)col;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, LARGEUR, HAUTEUR, "SALUT");
	fdf(mlx_ptr, win_ptr, line, col, LARGEUR, HAUTEUR, board);
	mlx_loop(mlx_ptr);
}

int		main(int argc, char **argv)
{
	int fd;
	int **board;
	int line;
	int col;
	int check;

	check = 1;
	if (basic_check(argc, argv) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	board = parsing(fd, argv, &line, &col, &check);
	if (check == -1)
	{
		write (1, "parsing failed : file is not same number of collumns", 52);
		return (-1);
	}
	launch_graphic(board, line, col);
	close(fd);
}
