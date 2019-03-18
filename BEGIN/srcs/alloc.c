/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:14:51 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/18 19:42:41 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**creat_tab(t_check *check)
{
	int		**board;
	int		*lilboard;
	int		i;

	i = 0;
	if (!(board = (int **)malloc(sizeof(board) * (check->line))))
		return (NULL);
	if (!(lilboard = (int *)malloc(sizeof(lilboard) \
					* (check->line * check->col))))
		return (NULL);
	while (i < check->line)
	{
		board[i] = &lilboard[i * check->col];
		i++;
	}
	return (board);
}
