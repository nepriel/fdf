/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 11:45:16 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/17 11:45:18 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*pdst;
	const char	*psrc;
	size_t		n;
	size_t		len_dst;

	pdst = dst;
	psrc = src;
	n = size;
	while (n-- != 0 && *pdst != 0)
		pdst++;
	len_dst = pdst - dst;
	n = size - len_dst;
	if (n == 0)
		return (len_dst + ft_strlen(psrc));
	while (*psrc)
	{
		if (n != 1)
		{
			*pdst++ = *psrc;
			n--;
		}
		psrc++;
	}
	*pdst = '\0';
	return (len_dst + (psrc - src));
}
