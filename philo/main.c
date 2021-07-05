#include "philo.h"

void	zeroing(t_common *common, int argc)
{
	if (argc == 6)
	{
		common->initial_data.number_of_philosophers = 0;
		common->initial_data.time_to_die = 0;
		common->initial_data.time_to_eat = 0;
		common->initial_data.number_of_philosophers = 0;
		common->initial_data.number_of_times_each_philosopher_must_eat = 0;
	}
	else
	{
		common->initial_data.number_of_philosophers = 0;
		common->initial_data.time_to_die = 0;
		common->initial_data.time_to_eat = 0;
		common->initial_data.number_of_philosophers = 0;
	}
}

int	main(int argc, char **argv)
{
	t_common *common;

	if (!(common = (t_common *)malloc(sizeof(t_common))))
	{
		put_str_fd("Error: malloc for common struct\n", 2);
		return (1);
	}
	if (argc == 5 || argc == 6)
	{
		zeroing(common, argc);
		if (parser(common, argv, argc) == 0)
			start_life(common);
		else
			return (1);
	}
	else
	{
		put_str_fd("Wrong amount of options\n", 2);
		return (1);
	}
}
