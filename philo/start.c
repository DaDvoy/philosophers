#include "philo.h"

void			*living_philos(void *one_of);
unsigned long	get_time(t_philos *philos);
int 			our_usleep(unsigned long micro_sec, t_philos *philos);

void			start_life(t_common *common)
{
	int i;

	i = 0;
	common->living = (pthread_t *)malloc(sizeof(pthread_t)
			* (common->initial_data.number_of_philosophers));
	if (!(common->living))
	{
		put_str_fd("Error: malloc for living\n", 2);
		return ;
	}
	while(i++ < common->initial_data.number_of_philosophers)
	{
		if ((pthread_create(&common->living[i], NULL,
			living_philos, (void *)(&common->philos[i]))) == -1)
		{
			put_str_fd("Error: pthread_create\n", 2);
			return ;
		}
		pthread_detach(common->living[i]);
	}
}

void		*living_philos(void *one_of)
{
	t_philos	*philos;
	int 		number;

	philos = (t_philos *)one_of;
	number = philos->number;// + 1;
	if (pthread_mutex_lock(philos->left))
	{
		printf("%lu: %d  has taken a fork\n", get_time(philos), number);
		pthread_mutex_lock(philos->right);
		printf("%lu: %d  has taken a fork\n", get_time(philos), number);
	}
	our_usleep(200, philos);
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(philos->right);
	printf("%lu: %d  is sleeping\n", get_time(philos), number);
	our_usleep(200, philos);
	printf("%lu: %d  is thinking\n", get_time(philos), number);
	return (NULL);
}

unsigned long	get_time(t_philos *philos)
{
	unsigned long	micro_sec;
	struct timeval	time;

	pthread_mutex_lock(&philos->end_time);
	gettimeofday(&time, NULL);
	micro_sec = time.tv_sec * 1000 + time.tv_usec / 1000;
	micro_sec = micro_sec - philos->start_time;
	pthread_mutex_unlock(&philos->end_time);
	return (micro_sec);
}

int 			our_usleep(unsigned long micro_sec, t_philos *philos)
{
	unsigned long	pause;
	unsigned long 	start;

	pause = get_time(philos) + micro_sec;
	start = get_time(philos);
	while (start < pause)
	{
		usleep(10);
		start = get_time(philos);
	}
	return (0);
}
