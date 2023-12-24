/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:32:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/24 11:49:58 by lpastor-         ###   ########.fr       */
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

/* NOTE: tiempos de argumentos en milisegundos
	- 1 milisegundo = 1s		* 1000
	- 1 milisegundo = 1micros	/ 1000
*/
# define CONVERSION_FACTOR 1000

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

/* Estructura con la información general */
struct s_data
{
	/* Array de filosofos */
	t_philo		*philos;			/* Ids de los hilos */
	
	/* Argumentos */
	int			number_philo;	/* Numero de filósofos */
	size_t		time_to_die;	/* Tiempo en morir */
	size_t		time_to_eat;	/* Tiempo en comer */
	size_t		time_to_sleep;	/* Tiempo en dormir */
	int			meals_needed;		/* Numero de comidas [opcional]*/

	/* Tiempo en el que empezo la somulacion */
	size_t		start;
	size_t		start_time;

	/* Declaracion de los mutex's */
	pthread_mutex_t	mutex_start;
	pthread_mutex_t	*forks;			/* Array de los mutex de los tenedores */
};

/* Estructura de filosofo */
struct s_philo
{
	/* Id del filosofo (indice de la tabla de filosofos + 1)*/
	int				id;

	/* Hilo del filosofo*/
	pthread_t		thread;

	/* Dead flag, si alguien muere se actualiza */
	int				end;
	
	/* Información de tiempos */
	t_data			*data;

	/* Informacion de comidas */
	int				meals_done;	/* Numero de comidas*/
	size_t			last_meal; /* Checkear haze cuanto comio el filosofo, para saber si ha muerto o no*/

	/* Mutex de los tenedores */
	/*
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	*/
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
};

/* Convertions */
size_t	ft_atull(char *str, int *flag);
int		ft_strict_atoi(char *str, int *flag);

/* Arguments */
int	read_arguments(t_data *data, int argc, char **argv);

/* Start env */
int	init_data(t_data *data, int argc, char **argv);
int	start_threads(t_data *data, void*(*routine)(void*));

/* Free memory */
void	delete_mutex(t_data *data);
void	delete_data(t_data *data);

/* Manage tasks */
void	*manage(void *data);

/* Time functions */
size_t	diff_time(struct timeval start, struct timeval end);
size_t	get_instant();

/* Sincronización */
void	start(t_data *data);
void	wait_start(t_data *data);

#endif