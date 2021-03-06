#include "philo.h"

int	loop_live(t_philos *philos, int number)
{
	if (philos->death == 1)
		return (1);
	pthread_mutex_lock(philos->left);
	pthread_mutex_lock(philos->right);
	if (philos->death == 1)
		return (1);
	print_fork(number, philos->start_time);
	pthread_mutex_lock(&philos->print);
	print_eat(number, philos->start_time);
	philos->last_time_meals = get_time(philos->start_time);
	pthread_mutex_unlock(&philos->print);
	our_usleep(philos->time_to_eat);
	philos->amount_meals++;
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(philos->right);
	if (philos->death == 1)
		return (1);
	print_sleep(number, philos->start_time);
	our_usleep(philos->time_to_sleep);
	if (philos->death == 1)
		return (1);
	print_think(number, philos->start_time);
	return (0);
}

void	*living_philos(void *one_of)
{
	t_philos	*philos;
	int			number;

	philos = (t_philos *)one_of;
	number = philos->number + 1;
	if (number % 2 == 0)
		our_usleep(5);
	while (1)
	{
		if (loop_live(philos, number) == 1)
			return (NULL);
		if (philos->number_of_times_each_philosopher_must_eat != -1
			&& philos->amount_meals
			== philos->number_of_times_each_philosopher_must_eat)
			break ;
	}
	return (NULL);
}

int	get_time(long start_time)
{
	struct timeval	actual;
	long			time;

	gettimeofday(&actual, NULL);
	time = (actual.tv_sec * 1000 + actual.tv_usec / 1000) - start_time;
	return (time);
}

void	our_usleep(long micro_sec)
{
	long		start;

	start = get_time(0);
	while (get_time(0) - start < micro_sec)
		usleep(50);
}
