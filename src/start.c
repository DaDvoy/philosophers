#include "philo.h"

void	start_life(t_common *common)
{
	common->living = (pthread_t *)malloc(sizeof(pthread_t)
			* (common->initial_data.number_of_philosophers));
	if (!(common->living))
		return (put_str_fd("Error: malloc for living\n", 2));
	if (common->initial_data.number_of_philosophers == 1)
		return (print_dead(1, common->philos[0].start_time - 1));
	thread_death(common);
	thread_living(common);
	free(common->living);
	free(common->philos);
	free(common->left_fork);
}

void	thread_death(t_common *common)
{
	if (pthread_create(&common->dying, NULL, death_philos, (void *)(common))
		== -1)
		return (put_str_fd("Error: pthread_create\n", 2));
	pthread_detach(common->dying);
}

void	thread_living(t_common *common)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < common->initial_data.number_of_philosophers && common->death
		!= 1)
	{
		if ((pthread_create(&common->living[i], NULL,
					living_philos, (void *)(&common->philos[i]))) == -1)
			return (put_str_fd("Error: pthread_create\n", 2));
	}
	while (++j < common->initial_data.number_of_philosophers)
	{
		pthread_join(common->living[j], NULL);
		pthread_detach(common->living[j]);
	}
}
