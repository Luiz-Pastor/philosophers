/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:18:53 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/24 18:38:31 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_philo *philo)
{
	size_t	start_time;
	size_t	diff;
	size_t	remaining;

	start_time = get_instant();
	while (get_instant() - start_time < philo->data->time_to_sleep)
	{
		/* Si alguien ha muerto, dejamos de dormir */
		if (is_finished(philo->data))
			break ;
		
		/* Hacemos calculos de tiempos  */
		diff = get_instant() - start_time;
		remaining = philo->data->time_to_sleep - diff;

		if (remaining > 1000)
			usleep(remaining / 2);
		else
		{
			while (get_instant() - start_time < philo->data->time_to_sleep)
				;
		}
	}
}