/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:32:13 by lpastor-          #+#    #+#             */
/*   Updated: 2024/03/21 12:31:21 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>		/* printf			*/
# include <stdlib.h>	/* malloc, free		*/
# include <string.h>	/* memset			*/
# include <unistd.h>	/* write, usleep	*/
# include <sys/time.h>	/* gettimeofday		*/
# include <pthread.h>	/* threads			*/

/* NOTE: tiempos de argumentos en milisegundos
	- 1 milisegundo = 1s		* 1000
	- 1 milisegundo = 1micros	/ 1000
*/
# define CONVERSION_FACTOR 1000

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

enum {
	EATING,
	SLEEPING,
	THINKING,
	FORK,
	DIED
};

/* Estructura con la información general */
struct s_data
{
	/* Array de filosofos */
	t_philo		*philos;			/* Ids de los hilos */
	int			threads_active;
	
	/* Argumentos */
	int			number_philo;	/* Numero de filósofos */
	size_t		time_to_die;	/* Tiempo que debe pasar sin comer para que muera un philo */
	size_t		time_to_eat;	/* Tiempo en comer */
	size_t		time_to_sleep;	/* Tiempo en dormir */
	int			meals_needed;		/* Numero de comidas [opcional]*/

	/* Tiempo en el que empezo la somulacion */
	size_t		start;
	size_t		start_time;

	/* Dead flag, si alguien muere se actualiza */
	int			end;

	/* Monitor de la simulacion */
	pthread_t	monitor;

	/* Declaracion de los mutex's */
	pthread_mutex_t	mutex_control;	/* Usado para saber cuando empezar y cuando terminar */
	pthread_mutex_t	mutex_terminal;	/* Para escribir los mensajes del status */
	pthread_mutex_t	*forks;			/* Array de los mutex de los tenedores */
};

/* Estructura de filosofo */
struct s_philo
{
	/* Id del filosofo (indice de la tabla de filosofos + 1)*/
	int				id;

	/* Hilo del filosofo*/
	pthread_t		thread;

	/* Dead */
	int				dead;
	
	/* Información de tiempos */
	t_data			*data;

	/* Informacion de comidas */
	int				meals_done;	/* Numero de comidas*/
	size_t			last_meal;	/* Checkear haze cuanto comio el filosofo, para saber si ha muerto o no*/
	int				satisfied;	/* Ha hecho todas las comidas que tenia que hacer */

	/* Mutex de los tenedores */
	/*
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	*/
	pthread_mutex_t	internal_mutex;	/* Usado para hacer operaciones internas */
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
int	start_threads(t_data *data, void *(*routine)(void*), void *(*one_philo)(void*), void *(*monitor)(void*));

/* Free memory */
void	delete_mutex(t_data *data);
void	delete_data(t_data *data);

/* Manage tasks */
void	*one_philo(void *data);
void	*philo_routine(void *arg);
/*void	*manage(void *data);*/

/* Time functions */
size_t	diff_time(struct timeval start, struct timeval end);
size_t	get_instant();
void	usleep_better(size_t time);

/* Sincronización */
void	start(t_data *data);
void	wait_start(t_data *data);
void	wait_monitor(t_data *data);
int		is_finished(t_data *data);

/* Output */
void	print_status(t_philo *philo, int status);

/* Actions */
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo, int beginning);

/* Monitor */
void	*monitor(void *table);

#endif