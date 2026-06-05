#include <unistd.h>

int     ft_strlen(char *str)
{
	int     len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	sort(char *str)
{
	int	i, j;
	char	tmp;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	permute(char *str, char *result, int *used, int position)
{
	int	i;

	if (position == ft_strlen(str))
	{
		write(1, result, position);
		write(1, "\n", 1);
		return ;
	}
	i = 0;
	while (str[i])
	{
		if (!used[i])
		{
			used[i] = 1;
			result[position] = str[i];
			permute(str, result, used, position + 1);
			used[i] = 0;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	result[42];
	int	used[42];
	int	i;

	if (ac != 2)
		return (1);
	sort(av[1]);
	i = 0;
	while (i < 42)
	{
		used[i] = 0;
		i++;
	}
	permute(av[1], result, used, 0);
	return (0);
}
