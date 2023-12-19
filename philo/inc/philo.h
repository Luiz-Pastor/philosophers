/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:32:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/19 21:48:56 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>		/* Printf */
# include <stdlib.h>	/* malloc, free*/
# include <string.h>	/* Memset */
# include <unistd.h>	/* Write, usleep */
# include <sys/time.h>	/* gettimeofday*/
# include <pthread.h>	/* Hilos */

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data
{
	unsigned long long	number_philo;	/* Numero de filósofos */
	unsigned long long	time_to_die;	/* Tiempo en morir */
	unsigned long long	time_to_eat;	/* Tiempo en comer */
	unsigned long long	time_to_sleep;	/* Tiempo en dormir */
	unsigned long long	eat_count;		/* Numero de comidas [opcional]*/

	pthread_t		*ids;			/* Ids de los hilos */
};

struct s_philo
{
	int		philo_number;
	t_data	*data;
};

#endif