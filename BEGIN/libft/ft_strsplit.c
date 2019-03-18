/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 07:34:31 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/18 07:34:36 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		nb_words;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_count_words_sep(s, c);
	if (!(str = ((char**)malloc(sizeof(*str) * (nb_words + 1)))))
		return (NULL);
	while (nb_words--)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_strlen_sep(s, c);
		str[i] = ft_strsub(s, 0, len);
		if (str[i] == '\0')
			return (NULL);
		s = s + ft_strlen_sep(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
