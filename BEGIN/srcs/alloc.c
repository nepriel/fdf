/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:14:51 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/15 17:16:37 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**creat_tab(int count_lines)
{
	int		**board;

	if (!(board = (int **)ft_memalloc(sizeof(**board) * (count_lines))))
		return (NULL);
	return (board);
}

int		*put_eachvalue_intab(char **eachvalue, t_check *check)
{
	int *tab;
	int i;

	i = 0;
	while (eachvalue[i])
		i++;
	if (i != check->col)
	{
		check->check = -1;
		return (NULL);
	}
	if (!(tab = (int *)ft_memalloc(sizeof(*tab) * (i))))
		return (NULL);
	i = 0;
	while (eachvalue[i])
	{
		tab[i] = atoi(eachvalue[i]);
		i++;
	}
	return (tab);
}
