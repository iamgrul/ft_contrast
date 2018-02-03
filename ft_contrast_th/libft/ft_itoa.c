/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:08:57 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/24 02:27:44 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_strlen(int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			strlen;
	unsigned int	i;

	strlen = get_strlen(n);
	i = n;
	if (n < 0)
	{
		i = -n;
		strlen++;
	}
	if (!(str = ft_strnew(strlen)))
		return (NULL);
	str[--strlen] = i % 10 + '0';
	while (i /= 10)
		str[--strlen] = i % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
