/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:32:11 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 09:54:13 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	free(data->philos);
	delete_mutex(data);
}
