/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:20:15 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/26 02:40:13 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *cur;

	if (!lst)
		return (NULL);
	cur = f(lst);
	new = cur;
	while (lst->next)
	{
		lst = lst->next;
		if (!(cur->next = f(lst)))
			return (NULL);
		cur = cur->next;
	}
	return (new);
}
