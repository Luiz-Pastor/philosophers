/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:34:23 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/24 11:51:17 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	wait_start(t_data *data)
{
	/* Bucle infinito hasta que `start` sea 1*/
	while (1)
	{
		pthread_mutex_lock(&data->mutex_start);
		if (data->start)
		{
			pthread_mutex_unlock(&data->mutex_start);
			break ;
		}
		pthread_mutex_unlock(&data->mutex_start);
	}
}

void	start(t_data *data)
{
	/* Nos guardamos el tiempo en el que empieza, para tener la referencia a la hora de mostrar los tiempos */
	data->start_time = get_instant();

	/* Cambiamos la variable de start a 1*/
	pthread_mutex_lock(&data->mutex_start);
	data->start = 1;
	pthread_mutex_unlock(&data->mutex_start);
}