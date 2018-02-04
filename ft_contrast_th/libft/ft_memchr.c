/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:41:11 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/24 15:33:35 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*dst;
	size_t		i;

	dst = (const char *)s;
	i = -1;
	while (++i < n)
		if (dst[i] == (char)c)
			return ((void *)dst + i);
	return (NULL);
}
