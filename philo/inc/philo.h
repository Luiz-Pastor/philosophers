/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:32:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/20 11:14:11 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>		/* printf 			*/
# include <stdlib.h>	/* malloc, free		*/
# include <string.h>	/* memset 			*/
# include <unistd.h>	/* write, usleep 	*/
# include <sys/time.h>	/* gettimeofday 	*/
# include <pthread.h>	/* hilos 			*/

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data
{
	int					number_philo;	/* Numero de filósofos */
	unsigned long long	time_to_die;	/* Tiempo en morir */
	unsigned long long	time_to_eat;	/* Tiempo en comer */
	unsigned long long	time_to_sleep;	/* Tiempo en dormir */
	int					eat_count;		/* Numero de comidas [opcional]*/

	pthread_t		*ids;			/* Ids de los hilos */
};

struct s_philo
{
	int		philo_number;
	t_data	*data;
};

/* Convertions */
unsigned long long	ft_atull(char *str, int *flag);
int					ft_strict_atoi(char *str, int *flag);

#endif