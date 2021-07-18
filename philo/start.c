#include "philo.h"

void			*living_philos(void *one_of);
ssize_t			get_time(ssize_t time);
void 			our_usleep(unsigned long micro_sec);

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
	pthread_mutex_lock(philos->left);
	printf("%lu: %d  has taken a fork\n", get_time(philos->start_time), number);
	pthread_mutex_lock(philos->right);
	printf("%lu: %d  has taken a fork\n", get_time(philos->start_time), number);
	pthread_mutex_lock(&philos->print);
	philos->time_last_meal = get_time(philos->start_time);
	printf("%lu  %d is eating\n", get_time(philos->start_time), number);
	pthread_mutex_unlock(&philos->print);
	philos->amount_meals++;
	our_usleep(philos->time_to_eat * 1000);                                                                                                                        
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(philos->right);
	printf("%lu: %d  is sleeping\n", get_time(philos->start_time), number);
	our_usleep(philos->time_to_eat * 1000);      // (200)need to change at time from structure
	printf("%lu: %d  is thinking\n", get_time(philos->start_time), number);
	// our_usleep(200); // (200)need to change at time from structure
	return (NULL);
}

ssize_t		get_time(ssize_t micro_sec)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - micro_sec);
}

void 		our_usleep(unsigned long micro_sec)
{
	struct timeval	start;
	struct timeval	pause;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&pause, NULL);
		if ((size_t)(((size_t)(pause.tv_sec - start.tv_sec)) * 1000000 +
				((size_t)(pause.tv_usec - start.tv_usec))) > micro_sec)
			break ;
	}
}
