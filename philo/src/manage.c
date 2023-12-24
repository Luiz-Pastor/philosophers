/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:27:15 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/24 13:31:35 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*manage(void *data)
{
	t_philo	*philo;

	/* Convertimos el parametro a filosofo */
	philo = (t_philo *) data;
	
	/* Esperamos que todos los hilos se hayan creado para empezar */
	// printf("Esperando %d...\n", philo->id);
	wait_start(philo->data);
	// printf("Hola desde %d => [%ld]\n", philo->id, philo->data->start);

	/* Empieza la simulacion */
	while (!is_finished(philo->data))
	{
		/*
			ACCIONES:
				1- Mirar si ya ha comido todo lo que deberia comer [parametro opcional]
				2- Comer
				3- Dormir
				4- Pensar
		*/

		/* TODO: comer */

		/* TODO: dormir */
		print_status(philo, SLEEPING);
		philo_sleep(philo);

		/* TODO: pensar */
		
	}
	return (NULL);	
}
