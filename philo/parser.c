#include "philo.h"

int		digit(char **argv, int argc);
void	distribution_forks();
void	fill_struct(t_common *common, char **argv, int argc);
void	refill_struct(t_common *common);
void	init_forks(t_common *common);

int		parser(t_common *common, char **argv, int argc)
{
	if (digit(argv, argc) != 1)
	{
		fill_struct(common, argv, argc);
		refill_struct(common);
		init_forks(common);
		distribution_forks(common);
		return (0);
	}
	else
		return (1);
}

int		digit(char **argv, int argc)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	while (count++ < argc)
	{
		if (is_digit(argv[i++]) == 1)
		{
			printf(RED "Error: wrong argument\n" RESET);
			return (1);
		}
	}
	return (0);
}

void	fill_struct(t_common *common, char **argv, int argc)
{
	int i;

	i = 1;
	common->initial_data.number_of_philosophers = char_to_int(argv[1]);
	common->initial_data.time_to_die = char_to_int(argv[2]);
	common->initial_data.time_to_eat = char_to_int(argv[3]);
	common->initial_data.time_to_sleep
		= char_to_int(argv[4]);
	if (argc > 5)
		common->initial_data.number_of_times_each_philosopher_must_eat
			= char_to_int(argv[5]);
	else
		common->initial_data.number_of_times_each_philosopher_must_eat = -1;
	common->left_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* common->initial_data.number_of_philosophers);
}

void	init_forks(t_common *common)
{
	int	j;

	j = 0;
	while (j < common->initial_data.number_of_philosophers)
	{
		common->philos[j].number = j;
		pthread_mutex_init(&common->left_fork[j], NULL);
		j++;
	}
	pthread_mutex_init(&common->philos->end_time, NULL);
}

void	distribution_forks(t_common *common)
{
	int i;

	i = 0;
	while (i < common->initial_data.number_of_philosophers - 1)
	{
		common->philos[i].left = &common->left_fork[i];
		common->philos[i].right = &common->left_fork[i + 1];
		i++;
	}
	common->philos[i].left = &common->left_fork[i];
	common->philos[i].right = &common->left_fork[1];
}

void	refill_struct(t_common *common)
{
	int i;

	i = 0;
	common->philos = (t_philos *)malloc(sizeof(t_philos)
		* (common->initial_data.number_of_philosophers));
	if (!common->philos)
		return (put_str_fd("Error: malloc for philo's\n", 2));
	while (i < common->initial_data.number_of_philosophers)
	{
		common->philos[i].start_time = get_time(0);
		common->philos[i].amount_meals = 0;
		common->philos[i].last_time_meals = 0;
		common->philos[i].number_of_philosophers = common->initial_data.number_of_philosophers;
		common->philos[i].time_to_die = common->initial_data.time_to_die;
		common->philos[i].time_to_eat = common->initial_data.time_to_eat;
		common->philos[i].time_to_sleep = common->initial_data.time_to_sleep;
		if (common->initial_data.number_of_times_each_philosopher_must_eat != -1)
			common->philos[i].number_of_times_each_philosopher_must_eat = common->initial_data.number_of_times_each_philosopher_must_eat;
		else 
			common->philos[i].number_of_times_each_philosopher_must_eat = -1;
		i++;
	}
}
