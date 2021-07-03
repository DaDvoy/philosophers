#include "philo.h"

int	main(int argc, char **argv)
{
	t_common	*common;

	i = 1;
	if (argc == 4 || argc == 5)
	{
		zeroing(common, argc);
		if (parser(common, argv, argc) == 0)
			start_life(common);
		else
			break ;
	}
	else
		put_str_fd("Wrong amount of options\n")
}
