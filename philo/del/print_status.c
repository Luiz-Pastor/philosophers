/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:51:36 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/25 14:04:38 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* [TIME] [PHILO_ID] [ACTION]*/
void	print_status(t_philo *philo, int status)
{
	size_t	actual_time;

	if (philo->satisfied)
		return ;

	actual_time = get_instant() - philo->data->start_time;

	pthread_mutex_lock(&philo->data->mutex_terminal);	

	if (status == EATING && !is_finished(philo->data))
		printf("%ld %d is eating\n", actual_time, philo->id);
	else if (status == SLEEPING && !is_finished(philo->data))
		printf("%ld %d is sleeping\n", actual_time, philo->id);
	else if (status == THINKING && !is_finished(philo->data))
		printf("%ld %d is thinking\n", actual_time, philo->id);
	else if (status == FORK && !is_finished(philo->data))
		printf("%ld %d has taken a fork\n", actual_time, philo->id);
	else /* DEAD*/
		printf("%ld %d is dead\n", actual_time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_terminal);	
}