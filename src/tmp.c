
#include <unistd.h>
#include "libft.h"
void	print_cmd_args(char **args)
{
	if (args == NULL)
	{
		ft_putstr_fd("*NULL*\n", STDERR_FILENO);
		return ;
	}
	ft_putstr_fd("[ ", STDERR_FILENO);
	while (*args != NULL)
	{
		ft_putstr_fd("<", STDERR_FILENO);
		ft_putstr_fd(*args, STDERR_FILENO);
		ft_putstr_fd("> ", STDERR_FILENO);
		args++;
	}
	ft_putstr_fd("]\n", STDERR_FILENO);
}
