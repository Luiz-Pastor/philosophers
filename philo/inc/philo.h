/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:32:13 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 10:23:52 by lpastor-         ###   ########.fr       */
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

/* NOTE: Time remember
	- 1 mili = 1s		* 1000
	- 1 mili = 1micro	/ 1000
*/
# define CONVERSION_FACTOR 1000

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

typedef enum s_action
{
	EATING,
	SLEEPING,
	THINKING,
	FORK,
	DIED
}			t_action;

typedef enum t_dead
{
	NO_DEAD = 0,
	SELF_DEAD,
	ANOTHER_DEAD
}			t_dead;

/* Struct with the main info */
struct s_data
{
	t_philo			*philos;			/* Pilo array */
	int				threads_active;		/* Number of threads (syncro) */
	int				number_philo;		/* Number of philos */
	size_t			time_to_die;		/* Time to die */
	size_t			time_to_eat;		/* Time to eat */
	size_t			time_to_sleep;		/* Time to sleep */
	int				meals_needed;		/* Meals needed (opcional) */
	size_t			start;				/* Flag to start the simulation*/
	size_t			start_time;			/* Time when the simulation started */
	int				end;				/* Flag to end the simulation */
	pthread_t		monitor;			/* Monitor thread */
	pthread_mutex_t	mutex_control;		/* Start/end of the simulation */
	pthread_mutex_t	mutex_terminal;		/* Print of msg on the terminal */
	pthread_mutex_t	*forks;				/* Forks mutex */
};

/* Philo struct */
struct s_philo
{
	int				id;				/* Filo id */
	pthread_t		thread;			/* Thread id */
	int				dead;			/* Dead flag */
	t_data			*data;			/* General struct data */
	int				meals_done;		/* Number of meals done */
	size_t			last_meal;		/* Time of the last meal */
	int				satisfied;		/* Flag to be satisfied */
	pthread_mutex_t	internal_mutex;	/* Internal mutex */
	pthread_mutex_t	*first_fork;	/* First fork mutex */
	pthread_mutex_t	*second_fork;	/* Second fork mutex */
};

size_t	ft_atull(char *str, int *flag);
int		ft_strict_atoi(char *str, int *flag);
int		read_arguments(t_data *data, int argc, char **argv);
int		init_data(t_data *data, int argc, char **argv);
int		start_threads(t_data *data, void *(*routine)(void*));
void	delete_mutex(t_data *data);
void	delete_data(t_data *data);
void	*one_philo(void *data);
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);
size_t	diff_time(struct timeval start, struct timeval end);
size_t	get_instant(void);
void	usleep_better(size_t time);
void	start(t_data *data);
void	wait_start(t_data *data);
void	wait_monitor(t_data *data);
t_dead	is_finished(t_philo *philo);
t_dead	check_self_dead(t_philo *philo);
void	print_action(t_philo *philo, t_action action);
int		eat_action(t_philo *philo);
int		is_satisfied(t_philo *philo);
void	think_action(t_philo *philo);

#endif