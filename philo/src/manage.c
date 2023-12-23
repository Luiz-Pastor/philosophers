/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:27:15 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/23 23:56:38 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*manage(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	
	printf("Te saluda el filosofo numero %d\n", philo->id);
	usleep(1000000);
	
	return (NULL);	
}
