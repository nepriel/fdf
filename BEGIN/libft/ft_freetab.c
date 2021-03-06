/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 11:30:09 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/17 11:30:11 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(char **tab, int nb)
{
	while (nb--)
		free(tab[nb]);
	free(tab);
	tab = NULL;
}
