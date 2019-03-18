/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:46:04 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/18 07:17:03 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

void	launch_graphic(int **board, int line, int col)
{
	t_mlx	mlx;

	mlx.line = line;
	mlx.col = col;
	mlx.board = board;
	mlx.hauteur = 500;
	mlx.largeur = 500;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.hauteur, mlx.largeur, "SALUT");
	fdf(&mlx);
	mlx_key_hook(mlx.win_ptr, ft_key_hook, (void *)0);
	mlx_loop(mlx.mlx_ptr);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		**board;
	t_check	check;

	check.check = 1;
	if (basic_check(argc, argv) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	board = parsing(fd, argv, &check);
	if (check.check == -1)
	{
		write(1, "parsing failed : file is not same number of collumns", 52);
		return (-1);
	}
	launch_graphic(board, check.line, check.col);
	close(fd);
}
