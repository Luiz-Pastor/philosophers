/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:26:08 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 10:11:41 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	pthread_mutex_init(&data->mutex_control, NULL);
	pthread_mutex_init(&data->mutex_terminal, NULL);
	return (0);
}

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
		data->philos[index].meals_done = 0;
		data->philos[index].satisfied = 0;
		if (pthread_mutex_init(&data->philos[index].internal_mutex, NULL))
		{
			free(data->philos);
			return (1);
		}
		index++;
	}
	return (0);
}

static void	assign_forks(t_data *data)
{
	int	index;
	int	count;

	index = 0;
	while (index < data->number_philo)
	{
		count = (index + 1) % data->number_philo;
		data->philos[index].first_fork = &data->forks[index];
		data->philos[index].second_fork = &data->forks[count];
		index++;
	}
	return ;
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (read_arguments(data, argc, argv))
		return (1);
	if (create_mutex(data))
		return (1);
	if (create_philo(data))
	{
		delete_mutex(data);
		return (1);
	}
	data->start = 0;
	data->end = 0;
	assign_forks(data);
	return (0);
}

int	start_threads(t_data *data, void *(*routine)(void*))
{
	int			index;
	pthread_t	*thread;
	t_philo		*philo;

	data->threads_active = 0;
	index = 0;
	while (index < data->number_philo)
	{
		thread = &data->philos[index].thread;
		philo = &data->philos[index];
		if (data->number_philo == 1)
		{
			if (pthread_create(thread, NULL, one_philo, philo))
				return (1);
		}
		else
		{
			if (pthread_create(thread, NULL, routine, philo))
				return (1);
		}
		index++;
	}
	pthread_create(&data->monitor, NULL, monitor_routine, data);
	start(data);
	return (0);
}
