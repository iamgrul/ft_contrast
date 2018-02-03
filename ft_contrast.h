/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:02:44 by ahuba             #+#    #+#             */
/*   Updated: 2018/02/02 20:05:11 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/types.h>

typedef struct	s_thread
{
	int			id;                        /* friendly id               */
	pthread_t	pthread;                   /* pointer to actual thread  */
//	struct thpool_ *thpool_p;            /* access to thpool          */
}				t_thread;

static volatile int threads_keepalive;

// typedef struct		s_
// {

// }					t_;

// void	();


#endif
