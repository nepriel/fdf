/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 11:47:18 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/17 11:47:21 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int			start;
	size_t		end;

	start = 0;
	if (!s)
		return (NULL);
	while (ft_isblank(s[start]) && s[start] != '\0')
		start++;
	end = ft_strlen(s);
	while (ft_isblank(s[end - 1]) && s[start] != '\0')
		end--;
	return (ft_strsub(s, start, end - start));
}
