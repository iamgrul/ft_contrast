/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:23:26 by ahuba             #+#    #+#             */
/*   Updated: 2018/01/12 12:23:53 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int	lstsize;

	if (lst == NULL)
		return (0);
	lstsize = 1;
	while (lst->next != NULL)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
