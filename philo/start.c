#include "philo.h"

void			*living_philos(void *one_of);
int				get_time(void);
void 			our_usleep(long micro_sec);

void			start_life(t_common *common)
{
	int i;

	i = -1;
	common->living = (pthread_t *)malloc(sizeof(pthread_t)
			* (common->initial_data.number_of_philosophers));
	if (!(common->living))
	{
		put_str_fd("Error: malloc for living\n", 2);
		return ;
	}
	while(++i < common->initial_data.number_of_philosophers)
	{
		// common->philos[i].start_time = get_time();
		if ((pthread_create(&common->living[i], NULL,
			living_philos, (void *)(&common->philos[i]))) == -1)
			return (put_str_fd("Error: pthread_create\n", 2));
	}
	i = -1;
	while (++i < common->initial_data.number_of_philosophers)
	{
		pthread_join(common->living[i], NULL);
		pthread_detach(common->living[i]);
	}
}

void		*living_philos(void *one_of)
{
	t_philos	*philos;
	int 		number;

	philos = (t_philos *)one_of;
	number = philos->number + 1;
	while (1)
	{
		pthread_mutex_lock(philos->left);
		pthread_mutex_lock(philos->right);
		// pthread_mutex_lock(&philos->print);
		printf(GREY "%u: "RESET" "YELLOW" %d has taken a fork\n" RESET, get_time() - philos->start_time, number);
		printf(GREY "%u: "RESET" "YELLOW" %d has taken a fork\n" RESET, get_time() - philos->start_time, number);
		// philos->present_time = get_time() - philos->start_time;
		printf(GREY "%u: "RESET" "GREEN" %d is eating\n" RESET, get_time() - philos->start_time, number);
		our_usleep(philos->time_to_eat);
		philos->amount_meals++;
		pthread_mutex_unlock(philos->left);
		pthread_mutex_unlock(philos->right);
		// pthread_mutex_unlock(&philos->print);
		printf(GREY "%u: "RESET" "CYAN" %d is sleeping\n" RESET, get_time() - philos->start_time, number);
		our_usleep(philos->time_to_sleep);
		printf(GREY "%u: "RESET" "MAGENTA" %d is thinking\n" RESET, get_time() - philos->start_time, number);
		our_usleep(philos->time_to_die);
	}
	return (NULL);
}

int		get_time(void)
{
	struct timeval	actual;
	long			time;

	gettimeofday(&actual, NULL);
	time = actual.tv_sec * 1000 + actual.tv_usec / 1000;
	return (time);
}

void 		our_usleep(long micro_sec)
{
	long		start;

	start = get_time();
	while (get_time() - start < micro_sec)
		usleep(100);
}
