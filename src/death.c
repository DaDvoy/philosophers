#include "philo.h"

void	state_death(t_common *common)
{
	int		i;

	i = -1;
	while (++i < common->initial_data.number_of_philosophers)
		common->philos[i].death = 1;
}

int	check_count_meals(t_common *common)
{
	int	 i;
	int	 flag;
	int	 amount_ate;

	i = -1;
	flag = 1;
	amount_ate = 0;
	while (++i < common->initial_data.number_of_philosophers)
	{
		if (common->philos[i].amount_meals
			== common->initial_data.amount_must_eat)
			amount_ate++;
	}
	if (amount_ate == common->initial_data.number_of_philosophers)
		flag = 0;
	return (flag);
}

int	count_meals(t_common *common)
{
	int	flag;

	flag = 0;
	if (common->initial_data.amount_must_eat
		!= -1 && check_count_meals(common) == 0)
	{
		state_death(common);
		flag = 1;
	}
	return (flag);
}

void	*death_philos(void *one_of)
{
	int			i;
	int			number;
	t_common	*common;

	common = (t_common *)one_of;
	while (1)
	{
		i = -1;
		while (++i < common->initial_data.number_of_philosophers)
		{
			number = common->philos[i].number + 1;
			if (get_time(common->philos[i].start_time)
				> (common->philos[i].last_time_meals
					+ common->philos[i].time_to_die))
			{
				print_dead(number, common->philos[i].start_time);
				state_death(common);
				return (NULL);
			}
		}
		if (count_meals(common) == 1)
			return (NULL);
	}
	return (NULL);
}
