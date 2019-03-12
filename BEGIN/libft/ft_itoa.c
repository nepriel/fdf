/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:52:08 by vlhomme           #+#    #+#             */
/*   Updated: 2018/11/22 11:00:12 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_isneg(int *sign, int *n)
{
	if (*n < 0)
	{
		*sign = 1;
		*n *= -1;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 2;
	sign = 0;
	ft_itoa_isneg(&sign, &n);
	while (tmp /= 10)
		len++;
	len += sign;
	if (!(str = (char *)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
