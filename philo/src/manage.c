/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:27:15 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/22 11:12:59 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*manage(void *data)
{
	t_philo	philo;

	philo = *(t_philo *) data;
	
	printf("Te saluda el filosofo numero %d\n", philo.id);
	return (NULL);	
}
