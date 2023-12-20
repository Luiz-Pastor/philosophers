/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:43:57 by lpastor-          #+#    #+#             */
/*   Updated: 2023/12/20 11:23:45 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_is_space(char ch)
{
	return (ch == ' ' || (ch >= 9 && ch <= 13));
}

static unsigned long long	ft_convertion_error(int *flag)
{
	if (flag)
		*flag = 1;
	return (0);
}

unsigned long long	ft_atull(char *str, int *flag)
{
	size_t				index;
	unsigned long long	count;
	
	count = 0;
	index = 0;
	*flag = 0;
	if (!str)
		return (ft_convertion_error(flag));
	while (str[index] && ft_is_space(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
		return (ft_convertion_error(flag));
	while (str[index] >= '0' && str[index] <= '9')
	{
		count = (count * 10) + (str[index] - '0');
		index++;
	}
	if (str[index])
		return (ft_convertion_error(flag));
	return (count);
}

int	ft_strict_atoi(char *str, int *flag)
{
	size_t	index;
	long	res[2];

	index = 0;
	res[0] = 0;
	res[1] = 1;
	*flag = 0;
	if (!str)
		ft_convertion_error(flag);
	while (str[index] && ft_is_space(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			res[1] = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res[0] = (res[0] * 10) + (str[index] - '0');
		index++;
	}
	if (str[index])
		return (ft_convertion_error(flag));
	return (res[0] * res[1]);
}
