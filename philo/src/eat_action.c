/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:22:02 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 09:33:16 by lpastor-         ###   ########.fr       */
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
	if (is_finished(philo))
		return (1);
	print_action(philo, FORK);

	/* Coger segundo tenedor */
	pthread_mutex_lock(philo->second_fork);
	if (is_finished(philo))
		return (1);
	print_action(philo, FORK);

	/* Comer --> esperar*/
	print_action(philo, EATING);
	usleep_better(philo->data->time_to_eat);

	/* Antes de acabar de comer, miramos si esta muerto */
	if (is_finished(philo))
	{
		/* Desbloqueamos tenedores*/
		unlock_forks(philo->first_fork, philo->second_fork);
		return (1);
	}

	/* Actualizar tiempos y cantidad de comidas */
	philo->last_meal = get_instant();

	pthread_mutex_lock(&philo->internal_mutex);
	philo->meals_done++;
	pthread_mutex_unlock(&philo->internal_mutex);

	/* Desbloqueamos mutex */
	unlock_forks(philo->first_fork, philo->second_fork);

	return (0);
}

int is_satisfied(t_philo *philo)
{
	int	meals_done;

	if (philo->data->meals_needed == -1)
		return 0;

	pthread_mutex_lock(&philo->internal_mutex);
	meals_done = philo->meals_done;
	pthread_mutex_unlock(&philo->internal_mutex);

	return (meals_done == philo->data->meals_needed);
}
