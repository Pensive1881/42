#include <>
#include <>
#include <>
#include <>
#define BUFFER_SIZE 10000

int	main(int ac, char **av)
{
	char bunnfer[BUFFER_SIZE];
	char *found;
	ssize_t read_ret;
	size_t slen;
	size_t i;

	if (ac != 2 || ! argv[1][0])
		return (1);
	slen = strlen(argv[1]);
	while ((read_ret = read(0, buffer, BUFFER_SIZE - 1)) > 0)
	{
		buffer[read_ret] = '\0';
		i = 0;
		while (i < size_t(read_ret))
		{
			found = memmem(buffer + i, read_ret - i, argv[1], slen);
			if (found)
			{
				write(1, buffer + i, found - (buffer + i));
				size_t	k = 0;
				while (k < slen)
				{
					write (1, "*", 1);
					k++;
				}
				i += found - (buffer + i) + slen;
			}
			else
			{
				write(1, buffer + i, read_ret - i);
				break;
			}
		}
	}
	if (read_ret < 0)
	{
		write(2, "Error: ", 7);
		perror("");
		return (1);
	}
	return (0);
}
