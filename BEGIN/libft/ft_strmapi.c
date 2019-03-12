/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:33:20 by vlhomme           #+#    #+#             */
/*   Updated: 2018/11/20 14:30:51 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		map[i] = f(i, map[i]);
		i++;
	}
	return (map);
}
