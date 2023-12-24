/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:26:08 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/24 12:00:20 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
	Inicializamos los mutex:
		- Forks
*/
static int	create_mutex(t_data *data)
{
	int	index;
	
	index = 0;
	data->forks = malloc(data->number_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	while (index < data->number_philo)
	{
		if (pthread_mutex_init(&data->forks[index], NULL))
		{
			while (--index >= 0)
				pthread_mutex_destroy(&data->forks[index]);
			return (1);
		}
		index++;
	}
	pthread_mutex_init(&data->mutex_start, NULL);
	return (0);
}

/* Inicializa todos los datos del filosofo menos el hilo y los mutex */
static int	create_philo(t_data *data)
{
	int	index;

	index = 0;
	data->philos = malloc(data->number_philo * sizeof(t_philo));
	if (!data->philos)
		return (1);
	while (index < data->number_philo)
	{
		data->philos[index].id = index + 1;
		data->philos[index].data = data;
		data->philos[index].end = 0;
		data->philos[index].meals_done = 0;
		data->philos[index].last_meal = 0;
		index++;
	}
	return (0);
}

/* TODO: pensar la táctica de selección de los tenedores para cada filosofo */
static void	assign_forks(t_data *data)
{
	(void)data;
	return ;
}

/* Inicializamos toda la información */
int	init_data(t_data *data, int argc, char **argv)
{
	/* Guardamos los argumentos */
	if (read_arguments(data, argc, argv))
		return (1);
	
	/* Creamos mutex */
	if (create_mutex(data))
		return (1);

	/* Creamos los filosofos, con sus datos */
	if (create_philo(data))
	{
		delete_mutex(data);
		return (1);
	}

	data->start = 0;
	
	assign_forks(data);
	return (0);
}

int	start_threads(t_data *data, void *(*routine)(void*))
{
	int	index;
	pthread_t	*thread;
	t_philo		*philo;

	/* Creamos los hilos */
	index = 0;
	while (index < data->number_philo)
	{
		thread = &data->philos[index].thread;
		philo = &data->philos[index];
		if (pthread_create(thread, NULL, routine, philo))
			return (1);
		index++;
	}

	/* Sincronizacion: los hilos esperan a que cambie el valor de `start`. Metemos 10ms de delay */
	usleep(10000);
	start(data);

	return (0);
}
