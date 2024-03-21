/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_thinking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:08:35 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/25 00:46:44 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* TODO: Modificar para evitar problemas */
void	philo_think(t_philo *philo, int beginning)
{
	long	think_time;
	
	if (!beginning)
		print_status(philo, THINKING);

	if (philo->data->number_philo % 2 == 0)
		return ;

	think_time = philo->data->time_to_eat * 2 - philo->data->time_to_sleep;
	if (think_time < 0)
		think_time = 0;

	usleep_better(think_time * .5);
}