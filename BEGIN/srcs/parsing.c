/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:16:26 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/18 07:15:35 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_lines(int fd, t_check *check)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (i == 0)
			check->col = ft_count_words_sep(line, ' ');
		i++;
		if (line)
			free(line);
	}
	close(fd);
	return (i);
}

/*void	free_eachvalue(char **eachvalue)
{
	int i;
	int len;
	
	i = 0;
	while (eachvalue[i])
		i++;
	len = i;
	i = 0;
	while (i < len)
	{
		free(eachvalue[i]);
		i++;
	}
	free(eachvalue);
}*/

void	print_board_content(int **board, t_check *check)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (k < check->line)
	{
		printf("\n eline %d : ", k);
		l = 0;
		while (l < check->col)
		{
			printf("%02d, ", board[k][l]);
			l++;
		}
		k++;
	}
}

int		**parsing(int fd, char **argv, t_check *check)
{
	char	*line;
	char	**eachvalue;
	int		j;
	int		i;
	int		**board;

	line = NULL;
	check->line = ft_count_lines(fd, check);
	fd = open(argv[1], O_RDONLY);
	if (!(board = creat_tab(check)))
		return (NULL);
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		eachvalue = ft_strsplit(line, ' ');
/*		if (check->check == -1)
			return (NULL);*/
		i = 0;
		while (eachvalue[i] != NULL)
		{
			board[j][i] = atoi(eachvalue[i]);
			free(eachvalue[i]);
			i++;
		}
		free(eachvalue);
		check->check = 0;
		free(line);
		j++;
	}
	print_board_content(board, check);
	return (board);
}
