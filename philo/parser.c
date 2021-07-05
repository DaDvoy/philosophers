#include "philo.h"

int	digit(char **argv);

int	parser(t_common *common, char **argv, int argc)
{
	if (digit(argv) != 1)
	{
		fill_struct(common, argv, argc);
		return (0);
	}
	else
		return (1);
}

int	digit(char **argv)
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

	j = 0;
	common->philos = (t_philos *)malloc(sizeof(t_philos)
		* (common->initial_data.number_of_philosophers));
	if (!common->philos)
		return (put_str_fd("Error: malloc for philo's\n", 2));
	common->initial_data.number_of_philosophers = char_to_int(argv[1]);
	common->initial_data.time_to_die = char_to_int(argv[2]);
	common->initial_data.time_to_eat = char_to_int(argv[3]);
	common->initial_data.time_to_sleep
		= char_to_int(argv[4]);
	if (argc == 6)
		common->initial_data.number_of_times_each_philosopher_must_eat
			= char_to_int(argv[5]);
	while (j++ < common->initial_data.number_of_philosophers)
		common->philos[j].number = j;
}
