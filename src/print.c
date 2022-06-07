#include "philo.h"

void	print_fork(int number, long time)
{
	printf(GREY "%d: "RESET" "YELLOW" %d has taken a fork\n" RESET,
		get_time(time), number);
	printf(GREY "%d: "RESET" "YELLOW" %d has taken a fork\n" RESET,
		get_time(time), number);
}

void	print_eat(int number, long time)
{
	printf(GREY "%d: "RESET" "GREEN" %d is eating\n" RESET,
		get_time(time), number);
}

void	print_sleep(int number, long time)
{
	printf(GREY "%d: "RESET" "CYAN" %d is sleeping\n" RESET,
		get_time(time), number);
}

void	print_think(int number, long time)
{
	printf(GREY "%d: "RESET" "MAGENTA" %d is thinking\n" RESET,
		get_time(time), number);
}

void	print_dead(int number, long time)
{
	printf(GREY "%d: "RESET" "RED" %d  died\n" RESET,
		get_time(time + 1), number);
}
