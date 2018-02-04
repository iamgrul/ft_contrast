/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 01:33:13 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/26 01:53:29 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (alst)
	{
		if (*alst)
		{
			cur = *alst;
			while (cur->next)
				cur = cur->next;
			cur->next = new;
		}
		else
			*alst = new;
	}
}
