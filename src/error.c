#include "../cub3D.h"

void	e_exit_num(t_cubed *cubed, int errnum, char *msg)
{
	errno = errnum;
	if (msg)
		perror(msg);
	printf("%s\n", strerror(errno));
	cleanup(cubed);
	exit(EXIT_FAILURE);
}

void	e_exit(t_cubed *cubed, char *msg)
{
	if (msg)
		perror(msg);
	printf("%s\n", strerror(errno));
	cleanup(cubed);
	exit(EXIT_FAILURE);
}

void	e_msg(char *msg, bool print_errno)
{
	if (msg)
		perror(msg);
	if (print_errno)
		printf("%s\n", strerror(errno));
}
