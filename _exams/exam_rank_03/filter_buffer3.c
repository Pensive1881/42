
int	main()
{
	int	i, j, r, len;
	char	buf[1000000];

	if ()
		return (1);
	r = read(0, buf, 1000000);
	if (r < 0)
		return (fprintf(stderr, "Error! "), perror(""), 1);
	len = strlen(av[1]);
	i = 0;
	while (i < r)
	{
		if (i <= r - len && !memcmp(buf + i, av[1], len))
		{
			while (j < len)
			{
				j = 0;
				write(1, "*", 1);
				j++;
			}
		}
		else
		{
			write(1, buf[i], 1);
			i++;
		}
	}
	return (0);
}
