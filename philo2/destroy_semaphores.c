/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_semaphores.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 23:50:55 by plamtenz          #+#    #+#             */
/*   Updated: 2020/12/17 01:59:36 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo2.h"

bool			destroy_semaphores(t_shared *const sh)
{
	uint32_t	i;
	char		*sname;

	i = 0;
	while (i < sh->nb)
	{
		sem_unlink(sname = sem_name(SEM_PHILO, i));
		free(sname);
		sem_unlink(sname = sem_name(SEM_EAT, i++));
		free(sname);
	}
	free(sh->philosophers);
	return (sem_unlink(SEM_FORK)
		&& sem_unlink(SEM_OUTPUT)
		&& sem_unlink(SEM_DEAD));
}
