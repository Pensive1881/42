#include <stdlib.h>

char *ft_strdup(char *src)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while(src[len])
		len++;
	dup = (char *)malloc(sizeof(char) * len+1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i]
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
