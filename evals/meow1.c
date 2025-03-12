#include <unistd.h>

void ft_meow(int n)
{
	char	c;
	int	i;
	char	numbers[];

	numbers = '0';
	c = '0';
	i = 0;
	while (i < n)
	{
		if (c % 2 == 0)
			write (1, "Even", 4);
		else
			write (1, "Odd", 3);
		i++;
		c++;
		numbers += i;
	}
	write (1, "\n", 1);
	write (1, &numbers, 2);
}
int main(void)
{
	ft_meow(20);

	return 0;
}
