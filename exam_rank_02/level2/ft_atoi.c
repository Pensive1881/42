#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i])
	{
		num += str[i] - '0';
		i++;
	}
	return (num);
}

/*
int	main(void)
{
	ft_atoi("42");
	return (0);
}
*/
