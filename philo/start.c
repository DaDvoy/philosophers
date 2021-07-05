#include "philo.h"

// I need to create thread for each philo's
// I think this do in "while"
//
//

void	*living_philos(void *one_of);

void	start_life(t_common *common)
{
	int i;

	i = 0;
	common->philos = (t_philos *)malloc(sizeof(t_philos)
			* (common->initial_data.number_of_philosophers));
	if (!common->philos)
		return (put_str_fd("Error: malloc for philo's\n", 2));
	common->living = (pthread_t *)malloc(sizeof(pthread_t)
			* (common->initial_data.number_of_philosophers));
	if (!(common->living))
	{
		put_str_fd("Error: malloc for living\n", 2);
		return ;
	}
	while(i++ < common->initial_data.number_of_philosophers)
	{
		if (!(pthread_create(&common->living[i], NULL,
			living_philos(&common->philos[i]), NULL)))
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
	printf("%d", philo->number);


	return (NULL);
	// with mutexes take fork
	// print that philo[number] take fork
	// again last point
	// 
	//
}