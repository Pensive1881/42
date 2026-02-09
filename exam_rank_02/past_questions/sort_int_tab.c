
void	ft_sort_int_tab(int *tab, int size)
{
	int	swapped;
	int	swap;
	int	i;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i+1] && tab[i+1]))
			{
				swap = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = swap;
				swapped = 1;
			}
			i++;
		}
	}
}

