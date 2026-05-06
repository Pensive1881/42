int	main(int ac, char **av)
{
	int	i, j, r;
	int	len;
	char	buf[10000];

	if ()
		return (1);
	r = read(0, buf, 10000);

	if (r<0)
		return (fprintf(stderr, "Error! "), perror (""), 1);
	len = strlen(av[1]);
	i = 0;
	while (i < r)
	{
		if (i <= j && !memmem(buf + i, av[1], len)
		{
			j = 0;
			while (j < len)
			{
				write(1, "*", 1);
				j++;
			}
			i += len;
		}
		else
		{
			write(1, &buf[i], 1);
			i++;
		}
	}
	return (0);
}
