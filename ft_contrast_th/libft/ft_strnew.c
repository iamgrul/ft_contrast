/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:10:33 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/14 18:17:34 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *buffer;

	buffer = malloc(sizeof(char) * size + 1);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size + 1);
	return (buffer);
}
