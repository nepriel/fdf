/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:57:38 by vlhomme           #+#    #+#             */
/*   Updated: 2018/11/11 12:44:59 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char*)malloc(sizeof(*copy) * ft_strlen(s1) + 1);
	if (copy == NULL)
		return (NULL);
	else
		ft_strcpy(copy, s1);
	return (copy);
}
