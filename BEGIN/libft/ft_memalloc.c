/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 11:34:15 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/17 11:34:17 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*storage_area;

	storage_area = malloc(size);
	if (storage_area == NULL)
		return (NULL);
	ft_bzero(storage_area, size);
	return (storage_area);
}
