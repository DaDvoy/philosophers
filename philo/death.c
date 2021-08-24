#include "philo.h"

int        check_count_meals(t_common *common)
{
    int     i;
    int     flag;
    int     amount_ate;

    i = -1;
    flag = 1;
    amount_ate = 0;
    while (++i < common->initial_data.number_of_philosophers)
    {
        if (common->philos[i].amount_meals == common->initial_data.number_of_times_each_philosopher_must_eat)
            amount_ate++;
    }
    if (amount_ate == common->initial_data.number_of_philosophers)
        flag = 0;
    return (flag);
}

void		*death_philos(void *one_of)
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
            // long now = get_time() - common->philos[i].start_time - 1000;
            // printf("%ld now time\n", now);
			if ((get_time() - common->philos[i].start_time) > (common->philos[i].last_time_meals + common->philos[i].time_to_die))
			{
            // printf("%ld die\n", common->philos[i].last_time_meals);
            // printf("%ld last time\n", common->philos[i].last_time_meals + common->initial_data.time_to_die);
				// pthread_mutex_lock(&common->philos[i].print);
                // pthread_mutex_lock(&common->dead);
                printf(GREY "%ld: "RESET" "RED" %d  died\n" RESET, get_time() - common->philos[i].start_time, number);
                common->philos->death = 1;
                // pthread_mutex_unlock(&common->philos[i].print);
                // return (NULL);
                exit (1);
			}
				// end of program(return NULL) + print die 
		}
        if (common->philos->number_of_times_each_philosopher_must_eat != -1 && check_count_meals(common))
            return (NULL);
		//  // count meals && == needed amount that  --- end of programm
	}
    return (NULL);
}