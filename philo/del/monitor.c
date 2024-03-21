/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:15:37 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/26 11:20:13 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo_died(t_philo *philo)
{
	size_t	interval;
	size_t	last_meal;


	pthread_mutex_lock(&philo->internal_mutex);
	if (philo->satisfied)
		return (1);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->internal_mutex);

	interval = get_instant() - last_meal;
	
	return (interval > philo->data->time_to_die);
}

void	*monitor(void *table)
{
	int		index;
	t_data	*data;

	data = (t_data *) table;
	
	/* Esperamos a la sincronización */
	wait_monitor(data);

	/* Bucle infinito hasta que acabe la simulacion */
	while (!is_finished(data))
	{
		index = 0;
		/* Miramos el estado de cada filosofo */
		while (index < data->number_philo && !is_finished(data))
		{
			if (philo_died(&data->philos[index]))
			{
				pthread_mutex_lock(&data->mutex_control);
				data->end = 1;
				print_status(&data->philos[index], DIED);
				pthread_mutex_unlock(&data->mutex_control);
			}
			index++;
		}
	}
	return NULL;
}
