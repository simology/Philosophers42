/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatifi <mlatifi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:40:10 by mlatifi           #+#    #+#             */
/*   Updated: 2022/09/27 18:47:22 by mlatifi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(long long time)
{
	long long	tmp;

	tmp = get_time();
	usleep(time * 1000 - 20000);
	while (get_time() < tmp + time)
		continue ;
}

long long	delta_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / (uint64_t)1000));
}

void	ft_free(t_config *instance)
{
	free (instance->forks);
	free (instance->philo);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}
