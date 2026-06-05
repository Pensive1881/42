#include <stdio.h>
#include <stdlib.h>

void	print(int *subset, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i)
			printf(" ");
		printf("%d", subset[i]);
		i++;
	}
	printf("\n");
}

void	powerset(int *set, int set_size, int n, int i, int *subset, int subset_size)
{
	if (i == set_size)
	{
		if (n == 0)
			print(subset, subset_size);
		return ;
	}
	subset[subset_size] = set[i];
	powerset(set, set_size, n - set[i], i + 1, subset, subset_size + 1);
	powerset(set, set_size, n, i + 1, subset, subset_size);
}

int	main(int ac, char **av)
{
	int	*set;
	int	*subset;
	int	n;
	int	i;

	if (ac < 2)
		return (1);
	n = atoi(av[1]);
	set = malloc(sizeof(int) * (ac - 2));
	subset = malloc(sizeof(int) * (ac - 2));
	if (!set || !subset)
		return (free(set), free(subset), 1);
	i = 2;
	while (i < ac)
	{
		set[i - 2] = atoi(av[i]);
		i++;
	}
	powerset(set, ac - 2, n, 0, subset, 0);
	free(set);
	free(subset);
	return (0);
}
