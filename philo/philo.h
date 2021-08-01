#ifndef PHILO_H
# define PHILO_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GREY    "\x1b[90m"
#define ANSI_COLOR_RESET   "\x1b[0m"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_common	t_common;

typedef struct s_philos {
	int				number;
	t_common		*common;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	pthread_mutex_t	end_time;
	pthread_mutex_t	print;
	ssize_t			present_time;
	ssize_t		 	start_time;
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
//	pthread_mutex_t	end_time;
//	unsigned long 	start_time;
}				t_common;

int				is_digit(int arg);
int				digit(char **argv);
int				len_str(char *str);
int				char_to_int(char *str);
ssize_t			get_time(ssize_t time);
void			refill(t_common *common);
void			start_life(t_common *common);
void			*living_philos(void *one_of);
void			put_str_fd(const char *s, int fd);
void			zeroing(t_common *common);//, int argc);
int				parser(t_common *common, char **argv, int argc);
void			fill_struct(t_common *common, char **argv, int argc);
#endif
