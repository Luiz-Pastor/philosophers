/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:31:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/19 23:03:02 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <limits.h>

int	print_help(char *execute)
{
	printf("Incorrect usage. Example:\n%s <number of philosophers>", execute);
	printf(" <time_to_die> <time_to_eat> <time_to_sleep>");
	printf(" [number_of_times_each_philosopher_must_eat]\n");
	printf("The last parameter is optional\n");
	return (1);
}

/*
ARGUMENTS (4 obligatorios + 1 opcional):
	- (1) number_of_philosophers						Número de filósofos
	- (2) time_to_die									Tiempo para morir
	- (3) time_to_eat									Tiempo para comer
	- (4) time_to_sleep									Tiempo para dormir
	- (5) [number_of_times_each_philosopher_must_eat]	Número de veces que cada filósofo ha de comer	<<<< OPCIONAL >>>> 
*/
/* TODO: coger los arguemntos y guardar los datos correctamente, con test de errores */
int	read_arguments(t_data *data)
{
	(void)data;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	(void)argv;

	if (argc != 5 && argc != 6)
		return (print_help(argv[0]));


	if (!read_arguments(&data))
	{
		printf("Error\n");
		return 1;
	}

	return (0);
}
