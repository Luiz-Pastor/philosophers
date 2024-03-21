/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:22:02 by lpastor-          #+#    #+#             */
/*   Updated: 2024/03/21 23:46:59 by lpastor-         ###   ########.fr       */
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
	t_dead	dead;

	/* Coger priemr tenerdor*/	
	pthread_mutex_lock(philo->first_fork);
	print_action(philo, FORK);

	/* Coger segundo tenedor */
	pthread_mutex_lock(philo->second_fork);
	print_action(philo, FORK);

	/* Comer --> esperar*/
	print_action(philo, EATING);
	usleep_better(philo->data->time_to_eat);

	/* Antes de acabar de comer, miramos si esta muerto */
	dead = check_self_dead(philo);
	if (dead)
	{
		/* Desbloqueamos tenedores*/
		unlock_forks(philo->first_fork, philo->second_fork);

		/* Miramos su hemos muerto nosotros, para imprimir mensaje */
		if (dead == SELF_DEAD)
			print_action(philo, DIED);

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