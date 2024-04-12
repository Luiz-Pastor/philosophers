/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:23:28 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 10:08:21 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_action(t_philo *philo, t_action action)
{
	size_t	actual_time;

	actual_time = get_instant() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_terminal);
	if (action == EATING && !is_finished(philo))
		printf("%ld %d is eating\n", actual_time, philo->id);
	else if (action == SLEEPING && !is_finished(philo))
		printf("%ld %d is sleeping\n", actual_time, philo->id);
	else if (action == THINKING && !is_finished(philo))
		printf("%ld %d is thinking\n", actual_time, philo->id);
	else if (action == FORK && !is_finished(philo))
		printf("%ld %d has taken a fork\n", actual_time, philo->id);
	else
		printf("%ld %d is dead\n", actual_time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_terminal);
}
