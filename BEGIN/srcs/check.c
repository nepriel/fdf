/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:55:09 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/19 16:36:06 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			end_by_fdftest(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if ((s[i - 1] != 'f' || s[i - 2] != 'd') || \
			(s[i - 3] != 'f' || s[i - 4] != '.'))
	{
		write(2, "Your file is not ending with '.fdf'\n", 36);
		return (0);
	}
	return (1);
}

int			check_content(char *s)
{
	char	*line;
	int		check;
	int		i;
	int		fd;

	i = 0;
	fd = open(s, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (i == 0)
			check = ft_count_words_sep(line, ' ');
		if (check == 1)
			return (-2);
		if (check != ft_count_words_sep(line, ' '))
			return (-1);
		i++;
		if (line)
			free(line);
	}
	if (i == 1)
		return (-3);
	if (i == 0)
		return (-4);
	close(fd);
	return (0);
}

static	int	a(void)
{
	write(2, "file is not same number of collumns\n", 36);
	return (1);
}

int			basic_check(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "you need an input file my dear\n", 31);
		return (-1);
	}
	if (argc == 2)
		if (!end_by_fdftest(argv[1]))
			return (-1);
	if (check_content(argv[1]) == -1)
		return ((a()) ? -1 : -1);
	if (check_content(argv[1]) == -2)
		return ((write(2, "There is not enough collumns\n", 29)) ? -1 : -1);
	if (check_content(argv[1]) == -3)
		return ((write(2, "There is not enough lines\n", 26)) ? -1 : -1);
	if (check_content(argv[1]) == -4)
		return ((write(2, "No data found\n", 14)) ? -1 : -1);
	if (argc > 2)
	{
		write(2, "You have to put only one file in argument\n", 42);
		return (-1);
	}
	return (0);
}
