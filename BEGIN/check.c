/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:55:09 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/13 11:51:05 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	end_by_fdftest(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if ((s[i - 1] != 'f' || s[i - 2] != 'd') || \
			(s[i - 3] != 'f' || s[i - 4] != '.'))
	{
		write(1, "Your file is not ending with '.fdf'\n", 36);
		return (0);
	}
	return (1);
}

/*
	** WARNING WE DONT CHECK RECTANGLE
 */

int	basic_check(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "you need an input file my dear\n", 31);
		return (-1);
	}
	if (argc == 2)
		if (!end_by_fdftest(argv[1]))
			return (-1);
	if (argc > 2)
	{
		write(1, "You have to put only one file in argument\n", 42);
		return (-1);
	}
	return (0);
}
