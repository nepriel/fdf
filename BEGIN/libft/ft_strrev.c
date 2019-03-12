/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:39:08 by vlhomme           #+#    #+#             */
/*   Updated: 2018/11/21 13:44:29 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	c;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		c = str[len];
		str[len] = str[i];
		str[i] = c;
		len--;
		i++;
	}
	return (str);
}
