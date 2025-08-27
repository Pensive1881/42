#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	n;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;

	return (s1[i] - s2[i]);
}


int	main(void)
{
	printf("meow & meow : %d\n", ft_strcmp("meow", "meow"));
	printf("miau & meow : %d\n", ft_strcmp("miau", "meow"));
	printf("meowmiau & meow : %d\n", ft_strcmp("meowmiau", "meow"));

	return (0);
}

