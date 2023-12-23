/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:09:16 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/23 23:47:16 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	read_arguments(t_data *data, int argc, char **argv)
{
	int	flag;

	data->number_philo = ft_strict_atoi(argv[1], &flag);
	if (flag || data->number_philo < 1)
		return (1);
	data->time_to_die = ft_atull(argv[2], &flag);
	if (flag)
		return (1);
	data->time_to_eat = ft_atull(argv[3], &flag);
	if (flag)
		return (1);
	data->time_to_sleep = ft_atull(argv[4], &flag);
	if (flag)
		return (1);
	if (argc == 5)
	{
		data->meals_needed = -1;
		return (0);
	}
	data->meals_needed = ft_strict_atoi(argv[5], &flag);
	if (flag || data->meals_needed < 1)
		return (1);
	return (0);
}
