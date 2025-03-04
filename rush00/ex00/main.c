// 42 header here

#include <unistd.h>

void	rush(int x, int y);

void	ft_print_newline(void)
{
	write(1, "\n", 1);
}

int	main(void)
{
	rush(5, 5);
	ft_print_newline();
	rush(5, 3);
	ft_print_newline();
	rush(5, 1);
	ft_print_newline();
	rush(1, 1);
	ft_print_newline();
	rush(1, 5);
	ft_print_newline();
	rush(4, 4);
	ft_print_newline();
	return (0);
}
