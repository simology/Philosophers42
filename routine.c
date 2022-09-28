/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatifi <mlatifi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:39:53 by mlatifi           #+#    #+#             */
/*   Updated: 2022/09/26 19:56:32 by mlatifi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_config	*instance;
	int			i;

	instance = (t_config *)args;
	i = instance->number_of_thread;
	instance->philo[i].last_meal = get_time();
	if (instance->num_of_times_eat > 0)
	{
		while (instance->num_of_times_eat > instance->philo[i].num_of_times_ate \
				&& instance->philo_dead == FALSE)
		{
			if (routine_execute(instance, i) == FALSE)
				break ;
		}
	}
	else
	{
		while (instance->philo_dead == FALSE)
		{
			if (routine_execute(instance, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_config *instance, int i)
{
	if (philo_eat(instance, i) == FALSE)
		return (FALSE);
	if (instance->num_of_times_eat != instance->philo[i].num_of_times_ate)
	{
		if (philo_sleep(instance, i) == FALSE)
			return (FALSE);
		if (philo_think(instance, i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

void	*check(void *args)
{
	t_config	*instance;
	int			i;

	instance = (t_config *)args;
	i = 0;
	if (instance->num_of_times_eat > 0)
	{
		while (instance->num_of_times_eat > instance->philo[i].num_of_times_ate \
				&& instance->philo_dead == FALSE)
		{
			if (philo_is_dead(instance, &i) == TRUE)
				break ;
		}
	}
	else
	{
		while (instance->philo_dead == FALSE)
		{
			if (philo_is_dead(instance, &i) == TRUE)
				break ;
		}
	}
	return (NULL);
}
