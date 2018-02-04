/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 02:45:07 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/26 03:20:25 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = NULL;
	node = ft_memalloc(sizeof(*node));
	if (node)
	{
		node->next = NULL;
		node->content = NULL;
		node->content_size = 0;
		if (content)
		{
			node->content_size = content_size;
			node->content = ft_memalloc(content_size);
			if (node->content)
				node->content = ft_memcpy(node->content, content, content_size);
			else
				ft_memdel((void**)&node);
		}
	}
	return (node);
}
