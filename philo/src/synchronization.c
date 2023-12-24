/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:34:23 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/24 12:25:38 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	wait_start(t_data *data)
{
	int	start;
	/* Bucle infinito hasta que `start` sea 1*/
	while (1)
	{
		pthread_mutex_lock(&data->mutex_control);
		start = data->start;
		pthread_mutex_unlock(&data->mutex_control);
		if (start)
			break ;
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
