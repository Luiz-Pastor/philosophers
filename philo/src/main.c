/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:31:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/22 11:15:38 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <limits.h>

void	print_data(t_data *data)
{
	printf("\n=> Numero de filosofos: %d\n", data->number_philo);
	printf("=> time_to_die: %zu\n", data->time_to_die);
	printf("=> time_to_eat: %zu\n", data->time_to_eat);
	printf("=> time_to_sleep: %zu\n", data->time_to_sleep);
	printf("=> eat_count: %d (%s)\n", data->eat_count, data->eat_count == -1 ? "no" : "si");
}

int	print_help(char *execute)
{
	printf("Incorrect usage. Example:\n%s <number of philosophers>", execute);
	printf(" <time_to_die> <time_to_eat> <time_to_sleep>");
	printf(" [number_of_times_each_philosopher_must_eat]\n");
	printf("The last parameter is optional\n");
	return (1);
}

void	wait_threads(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->number_philo)
	{
		pthread_join(data->philos[index].thread, NULL);
		index++;
	}
}

void	leaks()
{
	system("leaks -q philo");
}

int	main(int argc, char *argv[])
{
	atexit(leaks);
	t_data	data;

	if (argc != 5 && argc != 6)
		return (print_help(argv[0]));

	if (!read_arguments(argv, argc, &data))
	{
		printf("Error: invalida count/time\n");
		return (1);
	}
	if (!create_philo(&data))
		return (printf("Out of memory\n"));
	if (!create_mutex(&data) || !create_threads(&data))
	{
		delete_philos(&data);
		return (printf("Error creating the threads and/or mutex\n"));
	}
	create_mutex(&data);
	wait_threads(&data);
	print_data(&data);
	delete_philos(&data);
	return (0);
}
