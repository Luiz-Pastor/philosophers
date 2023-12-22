/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:26:08 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/22 11:13:58 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	read_arguments(char **argv, int argc, t_data *data)
{
	int	flag;

	data->number_philo = ft_strict_atoi(argv[1], &flag);
	if (flag || data->number_philo < 1)
		return (0);
	data->time_to_die = ft_atull(argv[2], &flag);
	if (flag)
		return (0);
	data->time_to_eat = ft_atull(argv[3], &flag);
	if (flag)
		return (0);
	data->time_to_sleep = ft_atull(argv[4], &flag);
	if (flag)
		return (0);
	if (argc == 5)
	{
		data->eat_count = -1;
		return (1);
	}
	data->eat_count = ft_strict_atoi(argv[5], &flag);
	if (flag || data->eat_count < 1)
		return (0);
	return (1);
}

int	create_philo(t_data *data)
{
	int	index;

	index = 0;
	data->philos = malloc(data->number_philo * sizeof(t_philo));
	if (!data->philos)
		return (0);
	while (index < data->number_philo)
	{
		data->philos[index].id = index + 1;
		data->philos[index].data = data;
		index++;
	}
	return (1);
}

int	create_threads(t_data *data)
{
	int			index;
	pthread_t	*current_thread;
	t_philo		*current_philo;

	index = 0;
	while (index < data->number_philo)
	{
		current_thread = &data->philos[index].thread;
		current_philo = &data->philos[index];
		if (pthread_create(current_thread, NULL, manage, current_philo))
		{
			perror("Hilo");
			return (0);
		}
		index++;
	}
	return (1);
}

int	create_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->mutex_terminal, NULL))
		return (0);
	return (1);
}

void	delete_philos(t_data *data)
{
	free(data->philos);
}
