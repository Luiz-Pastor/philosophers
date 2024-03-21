/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:31:32 by lpastor-          #+#    #+#             */
/*   Updated: 2024/03/21 10:49:53 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_data(t_data *data)
{
	printf("\n=> Numero de filosofos: %d\n", data->number_philo);
	printf("=> time_to_die: %zu\n", data->time_to_die);
	printf("=> time_to_eat: %zu\n", data->time_to_eat);
	printf("=> time_to_sleep: %zu\n", data->time_to_sleep);
	printf("=> eat_count: %d (%s)\n", data->meals_needed, data->meals_needed == -1 ? "no" : "si");
}

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

	/* Si todos se llenan, nadie muere y no se acaba el monitor */
	pthread_mutex_lock(&data->mutex_control);
	data->end = 1;
	pthread_mutex_unlock(&data->mutex_control);

	/*pthread_join(data->monitor, NULL);*/
}

/*void	leaks()
{
	system("leaks -q philo");
}*/

int	main(int argc, char *argv[])
{
	t_data	table;

	if (argc != 5 && argc != 6)
		return (print_help(argv[0]));

	/* Guaramos los arguentos en `table` e inicializamos todos los campos posibles */
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

	/* Empezamos los hilos */
	if (start_threads(&table, philo_routine, one_philo, monitor))
	{
		delete_data(&table);
		print_help(argv[0]);
		return (1);
	}

	/* Esperamos que acaben todos los hilos */
	wait_threads(&table);

	/* Eliminamos toda la memoria */
	delete_data(&table);

	return (0);
}
