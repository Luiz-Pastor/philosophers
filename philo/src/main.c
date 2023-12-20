/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:31:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/20 12:14:11 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <limits.h>

void	print_data(t_data *data)
{
	printf("=> Numero de fiosofos: %d\n", data->number_philo);
	printf("=> time_to_die: %llu\n", data->time_to_die);
	printf("=> time_to_eat: %llu\n", data->time_to_eat);
	printf("=> time_to_sleep: %llu\n", data->time_to_sleep);
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

/*
ARGUMENTS (4 obligatorios + 1 opcional):
	- (1) number_of_philosophers						Número de filósofos
	- (2) time_to_die									Tiempo para morir
	- (3) time_to_eat									Tiempo para comer
	- (4) time_to_sleep									Tiempo para dormir
	- (5) [number_of_times_each_philosopher_must_eat]	Número de veces que cada filósofo ha de comer	<<<< OPCIONAL >>>> 
*/
int	read_arguments(char **argv, int argc, t_data *data)
{
	int	flag;
	
	data->ids = NULL;
	data->number_philo = ft_strict_atoi(argv[1], &flag);
	if (flag || data->number_philo < 1)
		return (0);
	data->time_to_die = ft_atull(argv[2], &flag);
	if (flag)
		return (0);
	data->time_to_eat = ft_atull(argv[3], &flag);
	if (flag)
		return (0);
	data->time_to_sleep = ft_atull(argv[4], &flag);
	if (flag)
		return (0);
	if (argc == 5)
	{
		data->eat_count = -1;
		return (1);
	}
	data->eat_count = ft_strict_atoi(argv[5], &flag);
	if (flag || data->eat_count < 1)
		return (0);
	return (1);
}

void	wait_threads(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->number_philo)
	{
		pthread_join(data->ids[index], NULL);
		index++;
	}
}

void	*func(void *param)
{
	(void)param;
	printf("Alo\n");
	return NULL;
}

int	main(int argc, char *argv[])
{
	// t_data	data;
	(void)argv, (void)argc;

	/*if (argc != 5 && argc != 6)
		return (print_help(argv[0]));

	if (!read_arguments(argv, argc, &data))
	{
		printf("Error: invalida count/time\n");
		return (1);
	}
	data.ids = malloc(data.number_philo * sizeof(pthread_t));
	if (!data.ids)
	{
		printf("Error: out of memory\n");
		return (1);
	}
	create_pthreads(&data);
	wait_threads(&data);
	free(data.ids);
	return (0);*/
	pthread_t h1;

	pthread_create(&h1, NULL, func, NULL);

	usleep(10000000);

	pthread_join(h1, NULL);
	return 1;
}
