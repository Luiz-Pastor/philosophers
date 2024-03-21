/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:27:15 by lpastor-          #+#    #+#             */
/*   Updated: 2024/01/03 11:54:06 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	
	/* Sincronizamos */
	wait_start(philo->data);
	
	/* Marcamos el tiempo inicial de comida, para tener referencias */
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_instant();
	pthread_mutex_unlock(&philo->internal_mutex);

	/* Lo unico que puede hacer el filosofo es coger un tenerdor y pensar hasta que muera */
	print_status(philo, FORK);
	while (!is_finished(philo->data))
		usleep(200);
	return NULL;
}

static void	split_threads(t_philo *philo)
{
	if (philo->data->number_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
			usleep_better(30);
	}
	else
	{
		if (philo->id % 2)
			philo_think(philo, 1);
	}
}

void	*manage(void *data)
{
	t_philo	*philo;

	/* Convertimos el parametro a filosofo */
	philo = (t_philo *) data;
	
	/* Esperamos que todos los hilos se hayan creado para empezar */
	wait_start(philo->data);

	/* Hacemos que la ultima comida sea en este instante */
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_instant();
	pthread_mutex_unlock(&philo->internal_mutex);

	/* Elegimos quien empieza haciendo que, para evitar problemas de emparejamientos */
	split_threads(philo);

	/* Empieza la simulacion */
	while (!is_finished(philo->data))
	{
		/*
			ACCIONES:
				1- Mirar si ya ha comido todo lo que deberia comer [parametro opcional]
				2- Comer
				3- Dormir
				4- Pensar
		*/

		/* Comer */
		philo_eat(philo);

		/* Dormir */
		print_status(philo, SLEEPING);
		philo_sleep(philo);

		/* Pensar */
		philo_think(philo, 0);
	}
	return (NULL);	
}
