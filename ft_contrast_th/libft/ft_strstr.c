/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:04:29 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/09 17:44:14 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int len;
	int res;

	if (!strlen(needle))
		return ((char *)haystack);
	i = -1;
	res = 0;
	while (haystack[++i] && !res)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			len = i;
			res = 1;
			while (needle[j])
				if (needle[j++] != haystack[len++])
					res = 0;
			if (res)
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
