#include <stdio.h>

int	picoshell(char **cmds[]);

int	main(void)
{
    char	*cmd1[] = {"echo", "hello world", NULL};
    char	*cmd2[] = {"grep", "hello", NULL};
    char	*cmd3[] = {"wc", "-l", NULL};

    char	**cmds[] = {cmd1, cmd2, cmd3, NULL};

    int		ret = picoshell(cmds);

    printf("picoshell returned: %d\n", ret);
    return (ret);
}
