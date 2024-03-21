/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:34:23 by lpastor-          #+#    #+#             */
/*   Updated: 2024/03/21 11:02:55 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	wait_monitor(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->mutex_control);

		if (data->threads_active == data->number_philo)
		{
			pthread_mutex_unlock(&data->mutex_control);
			break ;
		}
		pthread_mutex_unlock(&data->mutex_control);
	}
}

void	wait_start(t_data *data)
{
	/* Bucle infinito hasta que `start` sea 1*/
	while (1)
	{
		pthread_mutex_lock(&data->mutex_control);
		if (data->start)
		{
			data->threads_active++;
			pthread_mutex_unlock(&data->mutex_control);
			break ;
		}
		pthread_mutex_unlock(&data->mutex_control);
	}
}

void	start(t_data *data)
{
	/* Nos guardamos el tiempo en el que empieza, para tener la referencia a la hora de mostrar los tiempos */
	data->start_time = get_instant();

	/* Cambiamos la variable de start a 1*/
	pthread_mutex_lock(&data->mutex_control);
	data->start = 1;
	pthread_mutex_unlock(&data->mutex_control);
}

int	is_finished(t_data *data)
{
	int	end;
	pthread_mutex_lock(&data->mutex_control);
	end = data->end;
	pthread_mutex_unlock(&data->mutex_control);
	return (end);
}
