/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:31:32 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 10:10:45 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	print_help(char *execute)
{
	printf("Incorrect usage. Example:\n%s <number of philosophers>", execute);
	printf(" <time_to_die> <time_to_eat> <time_to_sleep>");
	printf(" [number_of_times_each_philosopher_must_eat]\n");
	printf("The last parameter is optional\n");
	return (1);
}

static void	wait_threads(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->number_philo)
	{
		pthread_join(data->philos[index].thread, NULL);
		index++;
	}
	pthread_mutex_lock(&data->mutex_control);
	data->end = 1;
	pthread_mutex_unlock(&data->mutex_control);
	pthread_join(data->monitor, NULL);
}

int	main(int argc, char *argv[])
{
	t_data	table;

	if (argc != 5 && argc != 6)
		return (print_help(argv[0]));
	if (init_data(&table, argc, argv))
	{
		print_help(argv[0]);
		return (1);
	}
	if (table.meals_needed == 0)
	{
		delete_data(&table);
		return (0);
	}
	if (start_threads(&table, philo_routine))
	{
		delete_data(&table);
		print_help(argv[0]);
		return (1);
	}
	wait_threads(&table);
	delete_data(&table);
	return (0);
}
