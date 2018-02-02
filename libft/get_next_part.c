/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 22:03:28 by ahuba             #+#    #+#             */
/*   Updated: 2018/02/02 22:04:33 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_checkfd(t_list **gnl, int fd)
{
	t_list		*cur;

	cur = *gnl;
	while (cur)
	{
		if ((int)cur->content_size == fd)
			return (cur);
		cur = cur->next;
	}
	cur = ft_lstnew("\0", fd);
	ft_lstadd(gnl, cur);
	cur = *gnl;
	return (cur);
}

static int		decision(char **content, char **line, char *c, int len)
{
	char	*mem;

	if (ft_strlen(*content) == 0)
	{
		*line = ft_strnew(0);
		return (0);
	}
	else if ((mem = ft_strstr(*content, c)))
	{
		*line = ft_strsub(*content, 0, (size_t)(mem - content[0] + len));
		mem = *content;
		*content = ft_strdup(ft_strstr(*content, c) + 1);
		free(mem);
	}
	else if (ft_strlen(*content))
	{
		*line = ft_strdup((*content));
		free(*content);
		*content = ft_strnew(0);
	}
	return (1);
}

int				get_next_part(const int fd, char **line, char *c, int len)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*gnl;
	int				rid;
	char			*tmp;
	t_list			*cur;

	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	cur = ft_checkfd(&gnl, fd);
	*line = 0;
	if (!ft_strstr(cur->content, c))
		while ((rid = read(fd, buf, BUFF_SIZE)))
		{
			buf[rid] = '\0';
			tmp = cur->content;
			cur->content = ft_strjoin(cur->content, buf);
			free(tmp);
			if (ft_strstr(buf, c))
				break ;
		}
	return (decision((char **)&(cur->content), line, c, len));
}
