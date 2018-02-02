/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:10:39 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/03 23:28:08 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	bgn;
	unsigned int	end;
	char			*new_s;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		bgn = 0;
		end = ft_strlen(s) - 1;
		while ((s[bgn] == '\t' || s[bgn] == '\n' || s[bgn] == ' ')
				&& bgn < end + 1)
			bgn++;
		while ((s[end] == '\t' || s[end] == '\n' || s[end] == ' ')
				&& &s[end] != s)
			end--;
		if (bgn >= end || bgn == ft_strlen(s))
			return (ft_strnew(1));
		if ((new_s = ft_strnew(end - bgn + 1)))
		{
			ft_strncpy(new_s, s + bgn, end - bgn + 1);
			return (new_s);
		}
	}
	return (NULL);
}
