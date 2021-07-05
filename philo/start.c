#include "philo.h"

void	*living_philos(void *one_of);

void	start_life(t_common *common)
{
	int i;

	i = 0;
	common->living = (pthread_t *)malloc(sizeof(pthread_t)
			* (common->initial_data.number_of_philosophers));
	if (!(common->living))
	{
		put_str_fd("Error: malloc for living\n", 2);
		return ;
	}
	while(i++ < common->initial_data.number_of_philosophers)
	{
		if ((pthread_create(&common->living[i], NULL,
			living_philos, (void *)(&common->philos[i]))) == -1)
		{
			put_str_fd("Error: pthread_create\n", 2);
			return ;
		}
		pthread_detach(common->living[i]);
	}
}

void	*living_philos(void *one_of)
{
	t_philos  *philo;

	philo = (t_philos *)one_of;
	printf("%d\n", philo->number);
	usleep(100);


	return (NULL);
	// with mutexes take fork
	// print that philo[number] take fork
	// again last point
	// 
	//
}