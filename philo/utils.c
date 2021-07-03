#include "philo.h"

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	char_to_int(char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = a;
	while (str[a] == '\t' || str[a] == '\v' || str[a] == '\f' || str[a] == '\r'
		   || str[a] == '\n' || str[a] == ' ')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			b = b * -1;
		else
			b = 1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		c = c * 10 + str[a] - '0';
		a++;
	}
	return (c * b);
}

int	is_digit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}

void		put_str_fd(const char *s, int fd)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
