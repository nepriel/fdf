/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:19:45 by vlhomme           #+#    #+#             */
/*   Updated: 2018/11/20 14:29:08 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*map;

	if (!s || !f)
		return (NULL);
	if (!(map = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (map[i])
	{
		map[i] = f(map[i]);
		i++;
	}
	return (map);
}
