/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:32:28 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/24 19:42:07 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	m;
	int		res;

	i = -1;
	res = 1;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[++i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			m = i;
			res = 1;
			while (haystack[m] && needle[j] && j < len && m < len)
				if (haystack[m++] != needle[j++])
					res = 0;
			if (res && !(needle[j]))
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
