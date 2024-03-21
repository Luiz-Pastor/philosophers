/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:04:40 by lpastor-          #+#    #+#             */
/*   Updated: 2024/03/21 12:34:02 by lpastor-         ###   ########.fr       */
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

int is_finished(t_philo *philo)
{
	int state;
	
	/* Mirar si la flag en data de end está levantada */
	pthread_mutex_lock(&philo->data->mutex_control);
	state = philo->data->end;
	pthread_mutex_unlock(&philo->data->mutex_control);

	if (state)
		return (1);

	/*  Mirar si el propio filosofo ya está muerto --> tiempos */
	if (get_instant() - philo->last_meal > philo->data->time_to_die)
	{
		/* TODO: Notificar muerte del filosofo */
		pthread_mutex_lock(&philo->internal_mutex);
		philo->dead = 1;
		pthread_mutex_unlock(&philo->internal_mutex);
		return (1);
	}

	/* No ha muerto ningun filosofo */
	retrun (0);
}


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
		/* TODO: Dormir --> usleep_better */
		/* Pensar */
	}

	return NULL;
}
