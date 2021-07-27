#include "philo.h"

int		digit(char **argv);
void	distribution_forks();
void	fill_struct(t_common *common, char **argv, int argc);
void	refill_struct(t_common *common);

int		parser(t_common *common, char **argv, int argc)
{
	if (digit(argv) != 1)
	{
		fill_struct(common, argv, argc);
		refill_struct(common);
		return (0);
	}
	else
		return (1);
}

int		digit(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (is_digit(char_to_int(argv[i++])) == 1)
		{
			printf("Wrong argument\n");
			return (1);
		}
	}
	return (0);
}

void	fill_struct(t_common *common, char **argv, int argc)
{
	int i;
	int	j;

	i = 1;
	j = 0;
	common->initial_data.number_of_philosophers = char_to_int(argv[1]);
	common->philos = (t_philos *)malloc(sizeof(t_philos)
		* (common->initial_data.number_of_philosophers));
	if (!common->philos)
		return (put_str_fd("Error: malloc for philo's\n", 2));
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
	while (j++ < common->initial_data.number_of_philosophers)// && k++ < common->initial_data.number_of_philosophers - 1)
	{
		common->philos[j].number = j;
		printf("%d number philo: \n", common->philos[j].number);
		pthread_mutex_init(&common->left_fork[j], NULL);
	}
	pthread_mutex_init(&common->philos->end_time, NULL);
	distribution_forks(common);
}

void	distribution_forks(t_common *common)
{
	int i;

	i = 0;
	while (i++ < common->initial_data.number_of_philosophers - 1)
	{
		common->philos[i].left = &common->left_fork[i];
		common->philos[i].right = &common->left_fork[i + 1];
	}
	common->philos[i].left = &common->left_fork[i];
	common->philos[i].right = &common->left_fork[1];
	i = 0;
	while (i++ < common->initial_data.number_of_philosophers) {
		printf("%p left %d\n", common->philos[i].left, common->philos->number);
		printf("%p right %d\n", common->philos[i].right, common->philos->number++);
	}
}

void	refill_struct(t_common *common)
{
	common->philos->number_of_philosophers = common->initial_data.number_of_philosophers;
	common->philos->time_to_die = common->initial_data.time_to_die;
	common->philos->time_to_eat = common->initial_data.time_to_eat;
	common->philos->time_to_sleep = common->initial_data.time_to_sleep;
	if (common->initial_data.number_of_times_each_philosopher_must_eat != 0)
		common->philos->amount_meals = common->initial_data.number_of_times_each_philosopher_must_eat;
	else 
		common->philos->amount_meals = -1;
}

// common->philos[j]->left = &common->left_fork[i]
//common->philos[j]->right = &common->left_fork[i + 1]
// left - *com
// right -
