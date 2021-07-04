#include "philo.h"

// I need to create thread for each philo's
// I think this do in "while"
//
//

void	living_philos();

void	start_life(t_common *common)
{
	int i;

	i = 0;
	philos = (t_philos *)malloc(sizeof(t_philos)
			* (common->initial_data.number_of_philosophers));
	if (!philos)
		return (put_str_fd("Error: malloc for philo's\n", 2));
	common->eating = (pthread_t *)malloc(sizeof(pthread_t)
			* (common->initial_data.number_of_philosophers));
	common->dying = (pthread_t *)malloc(sizeof(pthread_t)
			* (common->initial_data.time_to_die));
	if (!(common->eating || common->dying))
	{
		put_str_fd("Error: malloc for eating or dying\n", 2);
		return ;
	}
	while(i++ < common->initial_data.number_of_philosophers)
	{
		pthread_create(/*smt struct */) // for i - each philo's
	}
}

void	living_philos()
{

}