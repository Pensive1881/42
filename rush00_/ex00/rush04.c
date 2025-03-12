// 42 header here

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	c;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			c = ' ';
			if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1))
				c = 'A';
			else if ((i == 0 && j == x - 1) || (i == y - 1 && j == 0))
				c = 'C';
			else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				c = 'B';
			ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
