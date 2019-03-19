/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:16:26 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/19 16:12:41 by vlhomme          ###   ########.fr       */
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

int		**parsing(int *j, int fd, char **argv, t_check *check)
{
	char	*line;
	char	**eachvalue;
	int		i;
	int		**board;

	check->line = ft_count_lines(fd, check);
	fd = open(argv[1], O_RDONLY);
	if (!(board = creat_tab(check)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		eachvalue = ft_strsplit(line, ' ');
		i = 0;
		while (eachvalue[i] != NULL)
		{
			board[*j][i] = ft_atoi(eachvalue[i]);
			free(eachvalue[i]);
			i++;
		}
		free(eachvalue);
		free(line);
		*j = *j + 1;
	}
	return (board);
}
