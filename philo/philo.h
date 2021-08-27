#ifndef PHILO_H
# define PHILO_H

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define GREY    "\x1b[90m"
# define RESET   "\x1b[0m"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_common	t_common;

typedef struct s_philos {
	int				number;
	t_common		*common;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	end_time;
	pthread_mutex_t	print;
	long			last_time_meals;
	int				death;
	long			start_time;
	int				amount_meals;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}				t_philos;

typedef struct s_initial {
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}				t_initial;

typedef struct s_common {
	t_initial		initial_data;
	t_philos		*philos;
	pthread_t		*living;
	pthread_t		dying;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	dead;
	unsigned int	start_time;
	int				death;
}				t_common;

int				is_digit(char *str);
int				digit(char **argv, int argc);
int				len_str(char *str);
int				char_to_int(char *str);
int				get_time(long start_time);
void			refill(t_common *common);
void			start_life(t_common *common);
void			*living_philos(void *one_of);
void			put_str_fd(const char *s, int fd);
void			zeroing(t_common *common);
int				parser(t_common *common, char **argv, int argc);
void			fill_struct(t_common *common, char **argv, int argc);
void			*death_philos(void *one_of);
void			our_usleep(long micro_sec);
void			thread_living(t_common *common);
void			thread_death(t_common *common);
void			print_fork(int number, long time);
void			print_eat(int number, long time);
void			print_sleep(int number, long time);
void			print_think(int number, long time);
void			print_dead(int number, long time);
#endif
