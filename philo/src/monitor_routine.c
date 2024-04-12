/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:56:52 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 10:00:44 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	set_finish(t_data *data)
{
	pthread_mutex_lock(&data->mutex_control);
	data->end = 1;
	pthread_mutex_unlock(&data->mutex_control);
}

static int	all_satisfied(int count, t_data *data)
{
	if (data->meals_needed == -1)
		return (0);
	if (count == data->number_philo)
	{
		set_finish(data);
		return (1);
	}
	return (0);
}

static int	is_anyone_dead(t_data *data, int index)
{
	int	dead;

	pthread_mutex_lock(&data->philos[index].internal_mutex);
	dead = data->philos[index].dead;
	pthread_mutex_unlock(&data->philos[index].internal_mutex);
	return (dead);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		index;
	int		end;
	int		satisfied;

	end = 1;
	data = (t_data *)arg;
	while (end)
	{
		index = 0;
		satisfied = 0;
		while (end && index < data->number_philo)
		{
			satisfied += is_satisfied(&data->philos[index]);
			if (is_anyone_dead(data, index))
			{
				set_finish(data);
				end = 0;
			}
			index++;
		}
		if (all_satisfied(satisfied, data))
			break ;
	}
	return (NULL);
}
