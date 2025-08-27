#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}

	return (i);
}

int	main(void)
{
	printf("hello, world, ,!: %zu\n", ft_strcspn("hello, world", ",!"));
	printf("abcdef, xyz: %zu\n", ft_strcspn("abcdef", "xyz"));
	printf("123-456, -: %zu\n", ft_strcspn("123-456", "-"));
	printf("hello, world, h: %zu\n", ft_strcspn("hello, world", "h"));

	return (0);
}

