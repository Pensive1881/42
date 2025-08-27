#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	int	i;
	int	bubble;

	bubble = 0;
	i = 0;
	if (!tab[i])
		return (0);
	while(tab[i])
	{
		if (tab[i] > bubble)
			bubble = tab[i];
		i++;
	}

	return (bubble);
}


int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	printf("1, 2, 3, 4, 5: %d\n", max(arr, 5));

	return (0);
}
