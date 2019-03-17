/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 11:49:45 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/17 11:49:48 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **tab)
{
	int		i;
	char	**tabcpy;

	tabcpy = ft_memalloc(ft_tablen(tab));
	i = 0;
	while (tab[i])
	{
		tabcpy[i] = ft_strdup(tab[i]);
		if (!tabcpy[i])
		{
			ft_freetab(tabcpy, i);
			return (NULL);
		}
		i++;
	}
	tabcpy[i] = NULL;
	return (tabcpy);
}
