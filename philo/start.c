#include "philo.h"

void			*living_philos(void *one_of);
unsigned long	get_time(void);
void 			our_usleep(unsigned long micro_sec);

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
		if ((pthread_create(&common->living[i], NULL,
			living_philos, (void *)(&common->philos[i]))) == -1)
		{
			put_str_fd("Error: pthread_create\n", 2);
			return ;
		}
		// pthread_detach(common->living[i]);
	}
	i = -1;
	while (++i < common->initial_data.number_of_philosophers){
		pthread_join(common->living[i], NULL);
		pthread_detach(common->living[i]);
	}
	// while (++i < common->initial_data.number_of_philosophers)
	// i = -1;
}

void		*living_philos(void *one_of)
{
	t_philos	*philos;
	int 		number;

	philos = (t_philos *)one_of;
	number = philos->number + 1;
	philos->start_time = get_time();
	// printf("%u %d TIME\n", philos->start_time, number);
	while (1)
	{
		pthread_mutex_lock(philos->left);
		pthread_mutex_lock(philos->right);
		pthread_mutex_lock(&philos->print);
		printf(GREY "%lu: "RESET" "YELLOW" %d has taken a fork\n" RESET, get_time() - 0 /*philos->start_time*/, number);
		printf(GREY "%lu: "RESET" "YELLOW" %d has taken a fork\n" RESET, get_time() - 0 /*philos->start_time*/, number);
		// philos->present_time = get_time() - 0 /*philos->start_time*/;
		printf(GREY "%lu: "RESET" "GREEN" %d is eating\n" RESET, get_time() - 0 /*philos->start_time*/, number);
		our_usleep(philos->time_to_eat);
		philos->amount_meals++;
		pthread_mutex_unlock(philos->left);
		pthread_mutex_unlock(philos->right);
		pthread_mutex_unlock(&philos->print);
		printf(GREY "%lu: "RESET" "CYAN" %d is sleeping\n" RESET, get_time() - 0 /*philos->start_time*/, number);
		our_usleep(philos->time_to_sleep);
		printf(GREY "%lu: "RESET" "MAGENTA" %d is thinking\n" RESET, get_time() - 0 /*philos->start_time*/, number);
		our_usleep(philos->time_to_die);
	}
	// pthread_detach(philos->living);
	return (NULL);
}

unsigned long		get_time(void)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	return (actual.tv_sec * 1000 + actual.tv_usec / 1000);
}

void 		our_usleep(unsigned long micro_sec)
{
	struct timeval	start;
	struct timeval	pause;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(10);
		gettimeofday(&pause, NULL);
		if ((size_t)(((size_t)(pause.tv_sec - start.tv_sec)) * 1000000 +
				((size_t)(pause.tv_usec - start.tv_usec))) > micro_sec)
			return ;
	}
}

// void    wait_for(long unsigned time)
// {
//     long unsigned   start;
//     start = get_time();
//     while (get_time() - start < time)
//         usleep(100);
// }