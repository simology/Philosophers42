/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatifi <mlatifi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:40:04 by mlatifi           #+#    #+#             */
/*   Updated: 2022/09/27 18:46:59 by mlatifi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_philo_struct(t_config *instance, int lf, int rf, char **argv)
{
	instance->philo[lf].id = lf;
	instance->philo[lf].num_of_times_ate = 0;
	instance->philo[lf].fork_left = lf;
	instance->philo[lf].fork_right = rf;
	instance->input_time_to_die = ft_atoi(argv[2]);
	instance->philo[lf].time_to_eat = ft_atoi(argv[3]);
	instance->philo[lf].time_to_sleep = ft_atoi(argv[4]);
	instance->num_of_times_eat = -1;
	if (argv[5])
		instance->num_of_times_eat = ft_atoi(argv[5]);
	return (TRUE);
}

int	ft_atoi(const char *str)
{
	size_t	c;
	int		s;
	int		res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] >= 9 && str[c] <= 13) || str[c] == 32)
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}

int	philo_print(t_config *instance, int id, char *status)
{
	long long	now;

	now = delta_time(instance->timing);
	if (instance->philo_dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&instance->write);
	if (instance->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&instance->write);
		return (FALSE);
	}
	else
		printf("%lld %d %s\n", now, id + 1, status);
	pthread_mutex_unlock(&instance->write);
	return (TRUE);
}

int	one_philo(t_config *in, int i)
{
	if (pthread_mutex_lock(&in->forks[in->philo[i].fork_left]) != 0)
		return (FALSE);
	if (philo_print(in, in->philo[i].id, FORK_LEFT) == FALSE)
		return (FALSE);
	if (pthread_mutex_unlock(&in->forks[in->philo[i].fork_left]) != 0)
		return (FALSE);
	in->philo_dead = TRUE;
	usleep(in->input_time_to_die * 1000);
	printf("%lld %d %s\n", in->input_time_to_die, 1, DIED);
	return (TRUE);
}

int	check_inputs(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (!(ft_isdigit(argv[1])) && !(ft_atoi(argv[1]) < 0))
			return (FALSE);
		if (!(ft_isdigit(argv[2])) && !(ft_atoi(argv[2]) < 0))
			return (FALSE);
		if (!(ft_isdigit(argv[3])) && !(ft_atoi(argv[3]) < 0))
			return (FALSE);
		if (!(ft_isdigit(argv[4])) && !(ft_atoi(argv[4]) < 0))
			return (FALSE);
		if (argc == 6)
		{
			if (!(ft_isdigit(argv[5])) && !(ft_atoi(argv[5]) < 0))
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}
