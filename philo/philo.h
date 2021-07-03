#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philos {
	//
}				t_philos;

typedef struct s_initial {
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}				t_initial;

typedef struct s_common {
	t_initial	initial_data;
	t_philos	*philos;
	pthread_t	*eating;
	pthread_t	*dying;


}				t_common;

int				is_digit(int arg);
int				digit(char **argv);
int				len_str(char *str);
int				char_to_int(char *str);
void			start_life(t_common *common);
void			put_str_fd(const char *s, int fd);
void			zeroing(t_common *common, int argc);
void			parser(t_common *common, char **argv);
void			fill_struct(t_common *common, char **argv, int argc);
#endif
