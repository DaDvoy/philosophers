#include "philo.h"

void	zeroing(t_common *common)
{
	common->initial_data.number_of_philosophers = 0;
	common->initial_data.time_to_die = 0;
	common->initial_data.time_to_eat = 0;
	common->initial_data.number_of_philosophers = 0;
	common->initial_data.amount_must_eat = 0;
	common->death = 0;
}

int	check_arg(t_common *common, int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (!(argc < 5 || argc > 6))
	{
		zeroing(common);
		if (parser(common, argv, argc) == 0)
			start_life(common);
		else
			flag = 1;
	}
	else
	{
		put_str_fd(RED "Error: wrong amount of options\n" RESET, 2);
		flag = 1;
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	int			flag;
	t_common	*common;

	flag = 1;
	common = (t_common *)malloc(sizeof(t_common));
	if ((common))
		flag = check_arg(common, argc, argv);
	else
		put_str_fd("Error: malloc for common struct\n", 2);
	free(common);
	return (flag);
}
