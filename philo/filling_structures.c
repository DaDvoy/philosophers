#include "philo.h"

void	zeroing(t_common *common, int argc)
{
	if (argc == 5)
	{
		common->initial_data.number_of_philosophers = 0;
		common->initial_data.time_to_die = 0;
		common->initial_data.time_to_eat = 0;
		common->initial_data.number_of_philosophers = 0;
		common->initial_data.number_of_times_each_philosopher_must_eat
	}
	else
	{
		common->initial_data.number_of_philosophers = 0;
		common->initial_data.time_to_die = 0;
		common->initial_data.time_to_eat = 0;
		common->initial_data.number_of_philosophers = 0;
	}
}