#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}


int	main(void)
{
	printf("42: %d\n", ft_atoi("42"));
	return (0);
}

