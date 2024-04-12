/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:34:23 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 10:11:54 by lpastor-         ###   ########.fr       */
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
	data->start_time = get_instant();
	pthread_mutex_lock(&data->mutex_control);
	data->start = 1;
	pthread_mutex_unlock(&data->mutex_control);
}
