/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:52:51 by vlhomme           #+#    #+#             */
/*   Updated: 2018/11/21 14:34:34 by vlhomme          ###   ########.fr       */
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
