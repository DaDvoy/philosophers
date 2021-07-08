#include "philo.h"

int		digit(char **argv);
void	distribution_forks();

int		parser(t_common *common, char **argv, int argc)
{
	if (digit(argv) != 1)
	{
		fill_struct(common, argv, argc);
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
	int j;
	int k;

	j = 0;
	k = 0;
	common->philos = (t_philos *)malloc(sizeof(t_philos)
		* (common->initial_data.number_of_philosophers));
	if (!common->philos)
		return (put_str_fd("Error: malloc for philo's\n", 2));
	common->initial_data.number_of_philosophers = char_to_int(argv[1]);
	common->initial_data.time_to_die = char_to_int(argv[2]);
	common->initial_data.time_to_eat = char_to_int(argv[3]);
	common->initial_data.time_to_sleep
		= char_to_int(argv[4]);
	if (argc == '6')
		common->initial_data.number_of_times_each_philosopher_must_eat
			= char_to_int(argv[5]);
	common->left_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* common->initial_data.number_of_philosophers);
//	k = common->initial_data.number_of_philosophers;
	while (j++ < common->initial_data.number_of_philosophers)
	{
		common->philos[j].number = j;
		pthread_mutex_init(&common->left_fork[k++], NULL);
//		pthread_mutex_init(&common->philos[j].left[k], NULL);
//		pthread_mutex_init(&common->philos[j].right[j], NULL);
	}
	pthread_mutex_init(&common->philos->end_time, NULL);
	distribution_forks(common);
}

void	distribution_forks(t_common *common)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	j = common->initial_data.number_of_philosophers;
	while (i++ < common->initial_data.number_of_philosophers)
	{
		common->philos[i].left = &common->left_fork[j - k];
		common->philos[i].right = &common->left_fork[k++];
		j--;
//		k++;
	}
	i = 0;
	while (i++ < common->initial_data.number_of_philosophers) {
		printf("%p left %d\n", common->philos[i].left, common->philos->number);
		printf("%p right %d\n", common->philos[i].right, common->philos->number++);
	}
}

// common->philos[j]->left = &common->left_fork[i]
//common->philos[j]->right = &common->left_fork[i + 1]
// left - *com
// right -
