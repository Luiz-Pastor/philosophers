/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:27:15 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/23 13:52:19 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*manage(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	
	(void)philo;
	/*pthread_mutex_lock(&philo->data->mutex_terminal);
	printf("Te saluda el filosofo numero %d\n", philo->id);
	usleep(1000000);
	pthread_mutex_unlock(&philo->data->mutex_terminal);*/
	
	return (NULL);	
}
