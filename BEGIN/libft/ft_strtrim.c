/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:34:05 by vlhomme           #+#    #+#             */
/*   Updated: 2018/11/21 13:24:19 by vlhomme          ###   ########.fr       */
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
