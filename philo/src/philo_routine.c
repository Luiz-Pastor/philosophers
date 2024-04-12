/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:04:40 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 10:07:53 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	wait_start(philo->data);
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_instant();
	pthread_mutex_unlock(&philo->internal_mutex);
	print_action(philo, FORK);
	while (!is_finished(philo))
		usleep(200);
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	wait_start(philo->data);
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_instant();
	pthread_mutex_unlock(&philo->internal_mutex);
	if (philo->id % 2)
		usleep_better(philo->data->time_to_eat);
	while (!is_finished(philo))
	{
		if (eat_action(philo))
			break ;
		if (is_satisfied(philo) || is_finished(philo))
			break ;
		print_action(philo, SLEEPING);
		usleep_better(philo->data->time_to_sleep);
		if (is_finished(philo))
			break ;
		think_action(philo);
	}
	return (NULL);
}
