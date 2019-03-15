/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:16:26 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/15 18:04:51 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_lines(int fd, char **argv)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		free(line);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	return (i);
}

int		countcol(char **eachvalue)
{
	int		i;

	i = 0;
	while (eachvalue[i])
		i++;
	return (i);
}

void	print_board_content(int **board, t_check *check)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (k < check->line)
	{
		l = 0;
		while (l < check->col)
		{
			printf("%02d, ", board[k][l]);
			l++;
		}
		printf("\n");
		k++;
	}
}

int		**parsing(int fd, char **argv, t_check *check)
{
	char	*line;
	char	**eachvalue;
	int		j;
	int		**board;

	line = NULL;
	check->line = ft_count_lines(fd, argv);
	board = creat_tab(check->line);
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		eachvalue = ft_strsplit(line, ' ');
		if (j == 0)
			check->col = countcol(eachvalue);
		board[j] = put_eachvalue_intab(eachvalue, check);
		if (check->check == -1)
			return (NULL);
		free(line);
		j++;
	}
	print_board_content(board, check);
	return (board);
}
