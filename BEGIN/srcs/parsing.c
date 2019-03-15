/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:16:26 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/15 16:45:33 by vlhomme          ###   ########.fr       */
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
	int i;

	i = 0;
	while (eachvalue[i])
		i++;
	return (i);
}

int		**parsing(int fd, char **argv, int *count_lines, int *col, int *check)
{
	char	*line;
	char	**eachvalue;
	int		j;
	int		**board;

	line = NULL;
	*count_lines = ft_count_lines(fd, argv);
	board = creat_tab(*count_lines);
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		eachvalue = ft_strsplit(line, ' ');
		if (j == 0)
			*col = countcol(eachvalue);
		board[j] = put_eachvalue_intab(eachvalue, col, check);
		if (*check == -1)
			return (NULL);
		free(line);
		j++;
	}
		int k = 0, l = 0;
		while (k < *count_lines)
		{
		l = 0;
		while (l < *col)
		{
		printf("%02d, ", board[k][l]);
		l++;
		}
		printf("\n");
		k++;
		}
	return (board);
}
