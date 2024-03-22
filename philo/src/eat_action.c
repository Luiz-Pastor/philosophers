/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:22:02 by lpastor-          #+#    #+#             */
/*   Updated: 2024/03/22 11:39:22 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	unlock_forks(pthread_mutex_t *first, pthread_mutex_t *second)
{
	if (first)
		pthread_mutex_unlock(first);

	if (second)
		pthread_mutex_unlock(second);
	
}

int	eat_action(t_philo *philo)
{
	/* Coger priemr tenerdor*/	
	pthread_mutex_lock(philo->first_fork);
	print_action(philo, FORK);

	if (is_finished(philo))
		return (1);

	/* Coger segundo tenedor */
	pthread_mutex_lock(philo->second_fork);
	print_action(philo, FORK);

	if (is_finished(philo))
		return (1);

	/* Comer --> esperar*/
	print_action(philo, EATING);
	usleep_better(philo->data->time_to_eat);

	/* Antes de acabar de comer, miramos si esta muerto */
	if (check_self_dead(philo))
	{
		/* Desbloqueamos tenedores*/
		unlock_forks(philo->first_fork, philo->second_fork);
		return (1);
	}

	/* Actualizar tiempos y cantidad de comidas */
	philo->last_meal = get_instant() - philo->data->start_time;

	pthread_mutex_lock(&philo->internal_mutex);
	philo->meals_done++;
	pthread_mutex_unlock(&philo->internal_mutex);

	/* Desbloqueamos mutex */
	unlock_forks(philo->first_fork, philo->second_fork);

	return (0);
}