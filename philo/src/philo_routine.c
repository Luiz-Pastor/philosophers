/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:04:40 by lpastor-          #+#    #+#             */
/*   Updated: 2024/03/21 23:54:48 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* FIXME: faltan funciones borradas */
/*void	*one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	
	// Sincronizamos
	wait_start(philo->data);
	
	// Marcamos el tiempo inicial de comida, para tener referencias
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_instant();
	pthread_mutex_unlock(&philo->internal_mutex);

	// Lo unico que puede hacer el filosofo es coger un tenerdor y pensar hasta que muera
	print_status(philo, FORK);
	while (!is_finished(philo->data))
		usleep(200);
	return NULL;
}*/

void *one_philo(void *data) {(void)data; return NULL;}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	/* Recogemos la estructura del filosofo */
	philo = (t_philo*) arg;

	/* Esperamos a que todos los hilos esten preparados */
	wait_start(philo->data);

	/* Hacemos que la ultima comida sea en este instante */
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_instant();
	pthread_mutex_unlock(&philo->internal_mutex);

	/* Hacemos que los pares se retrasen un poco */
	/* TODO: mirar el retrasar a los pares x tiempo */
	usleep_better(philo->id * 1000);

	while (!is_finished(philo))
	{
		/* TODO: Comer */
		if (eat_action(philo))
		{
			/* Ha muerto o ha terminado la ejecucion */
			break ;
		}
		
		/* Dormir */
		if (is_finished(philo))
			break ;

		usleep_better(philo->data->time_to_sleep);

		if (is_finished(philo))
			break ;

		/* Pensar */
		think_action(philo);
	}

	return NULL;
}
