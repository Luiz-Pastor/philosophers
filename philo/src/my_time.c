/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:47:13 by lpastor-          #+#    #+#             */
/*   Updated: 2024/04/12 08:48:37 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

size_t	diff_time(struct timeval start, struct timeval end)
{
	size_t	start_time;
	size_t	end_time;

	start_time = start.tv_sec * 1000 + start.tv_usec / 1000;
	end_time = end.tv_sec * 1000 + end.tv_usec / 1000;

	return end_time - start_time;
}

size_t	get_instant()
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * CONVERSION_FACTOR + now.tv_usec / CONVERSION_FACTOR);
}

void	usleep_better(size_t time)
{
	size_t	begin;

	begin = get_instant();

	while (get_instant() - begin < time)
		usleep(200);
}
