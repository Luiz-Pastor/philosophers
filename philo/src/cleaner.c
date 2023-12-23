/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:32:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/23 23:48:07 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
Memoria a elimiar:
	- Eliminar tabla de mutex
		· Eliminar cada mutex
	- Eliminar tabla de filosofos
*/

void	delete_mutex(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->number_philo)
	{
		pthread_mutex_destroy(&data->forks[index]);
		index++;
	}
	free(data->forks);
}

void	delete_data(t_data *data)
{
	/* Eliminamos la tabla de filosofos */
	free(data->philos);

	/* Eliminamos la tabla de mutex */
	delete_mutex(data);
}