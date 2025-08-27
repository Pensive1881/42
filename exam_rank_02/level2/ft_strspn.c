#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	num;

	num = 0;
	i = 0;
	while(s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				num++;
			j++;
		}
		i++;
	}
	return (num);
}

int	main(void)
{
	printf("hello123, abcdefghijklmnopqrstuvwxyz: %zu\n", ft_strspn("hello123", "abcdefghijklmnopqrstuvwxyz"));
	printf("hello123, abcdefghijklmnopqrstuvwxyz: %zu\n", ft_strspn("123hello", "0123456789"));

	return (0);
}

