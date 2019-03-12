/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:15:20 by vlhomme           #+#    #+#             */
/*   Updated: 2018/11/21 09:53:58 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (!s)
		return (words);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	if (s[0] != '\0')
		words++;
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		len;

	if (!s || !c || !(split = (char **)ft_memalloc(sizeof(s) * \
					ft_count_words(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			split[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	split[j] = NULL;
	return (split);
}
