/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatifi <mlatifi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:39:35 by mlatifi           #+#    #+#             */
/*   Updated: 2022/09/26 19:59:54 by mlatifi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_config	config;

	if (!check_inputs(argc, argv))
	{
		printf("Error inputs ! \n");
		return (FALSE);
	}
	if (create_philos(&config, argv) == FALSE)
		return (1);
	if (create_forks(&config) == FALSE)
		return (1);
	if (config.num_philo > 1)
		create_threads(&config);
	else
		one_philo(&config, 0);
	destroy_threads(&config);
	ft_free(&config);
	return (0);
}
