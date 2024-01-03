/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:51:19 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/25 00:46:32 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_eat(t_philo *philo)
{
	/* Cogemos el primer tenedor e informamos */
	pthread_mutex_lock(philo->first_fork);
	print_status(philo, FORK);

	/* Cogemos el segundo tenedor e informamos */
	pthread_mutex_lock(philo->second_fork);
	print_status(philo, FORK);

	/* Cambiamos la fecha de la ultima comida. Necesitamos un mutex para prevenir lectura del monitor */
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_instant();
	philo->meals_done++;
	pthread_mutex_unlock(&philo->internal_mutex);

	/* Imprimimos que ha comido */
	print_status(philo, EATING);

	/* Esperamos el tiempo que se dedica a comer */
	// philo_sleep(philo);
	usleep_better(philo->data->time_to_sleep);

	/* Miramos si el filosofo está lleno */
	if (philo->meals_done == philo->data->meals_needed)
	{
		pthread_mutex_lock(&philo->internal_mutex);
		philo->satisfied = 1;
		pthread_mutex_unlock(&philo->internal_mutex);
	}

	/* Desbloqueamos los forks */
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}
