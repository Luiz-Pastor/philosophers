/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finished.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:29:41 by lpastor-          #+#    #+#             */
/*   Updated: 2024/03/22 11:40:08 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_dead	check_self_dead(t_philo *philo)
{
	if (get_instant() - philo->last_meal > philo->data->time_to_die)
	{
		/* Cambiamos valor a 1 */
		pthread_mutex_lock(&philo->internal_mutex);	
		philo->dead = 1;
		pthread_mutex_unlock(&philo->internal_mutex);

		/* Notificamos muerte */
		print_action(philo, DIED);

		return (SELF_DEAD);
	}
	return (NO_DEAD);
}

t_dead is_finished(t_philo *philo)
{
	int state;
	
	/* Mirar si la flag en data de end está levantada */
	pthread_mutex_lock(&philo->data->mutex_control);
	state = philo->data->end;
	pthread_mutex_unlock(&philo->data->mutex_control);
	if (state)
		return (ANOTHER_DEAD);

	/* Sino, miramos si el propio filósofo ha muerto*/
	return (check_self_dead(philo));
}