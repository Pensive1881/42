int	main()
{
	char	buf[1000000];
	int	i, j, r, len;

	if (ac != 2 || !av[1][0])
		return (1);
	r = read(0, buf, 10000000);
	if (r < 0)
		return (pfrintf(stderr, "Error! "), perror(""), 1);
	len = ft_strlen(av[1]);
	i = 0;
	while (i < r)
	{
		if (i <= r - len && !memcmp(buf + i, av[1], len))
		{
			j++;
			while (j < len)
			{
				write(1, "*", 1);
				j++;
			}
		}
		else
		{
			write(1, &buf, 1);
			i++;
		}
	}
	return (0);
}
