/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:35:53 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/14 16:35:53 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char ***tab)
{
	char	**tmp;

	tmp = *tab;
	while (**tab)
	{
		free(**tab);
		(*tab)++;
	}
	free(tmp);
}

void	ft_freen(char ***tab, int n)
{
	char	**tmp;

	tmp = *tab;
	while (n)
	{
		free(**tab);
		(*tab)++;
		n--;
	}
	free(tmp);
}
