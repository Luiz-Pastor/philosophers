/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:32:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/22 11:12:02 by lpastor-         ###   ########.fr       */
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
	t_philo		*philos;			/* Ids de los hilos */
	
	int			number_philo;	/* Numero de filósofos */
	size_t		time_to_die;	/* Tiempo en morir */
	size_t		time_to_eat;	/* Tiempo en comer */
	size_t		time_to_sleep;	/* Tiempo en dormir */
	int			eat_count;		/* Numero de comidas [opcional]*/

	pthread_mutex_t	mutex_terminal;
};

struct s_philo
{
	int			id;
	pthread_t	thread;
	t_data		*data;
};

/* Convertions */
size_t	ft_atull(char *str, int *flag);
int		ft_strict_atoi(char *str, int *flag);

/* Set/get data */
int	read_arguments(char **argv, int argc, t_data *data);
int	create_philo(t_data *data);
int	create_threads(t_data *data);
int	create_mutex(t_data *data);
void	delete_philos(t_data *data);

/* Manage tasks */
void	*manage(void *data);

#endif