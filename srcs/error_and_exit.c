#include "../includes/minirt.h"

void	error_and_exit(int code)
{
	if (code == -1)
		write(STDERR_FILENO, "Error\nCan't allocate memory\n", 29);
	if (code == -2)
		write(STDERR_FILENO, "Error\nWrong number of arguments\n", 33);
	if (code == -3)
		write(STDERR_FILENO, "Error\nNo such file or directory\n", 33);
	if (code == -4)
		write(STDERR_FILENO, "Error\nNo extension\n", 20);
	if (code == -5)
		write(STDERR_FILENO, "Error\nInvalid extension\n", 25);
	if (code == -6)
		write(STDERR_FILENO, "Error\nInvalid scene description\n", 33);
	if (code == -7)
		write(STDERR_FILENO, "Error\nError with ""save""\n", 23);
	if (code == -8)
		write(STDERR_FILENO, "Error\nBad resolution\n", 22);
	if (code == -9)
		write(STDERR_FILENO, "Error\nBad range\n", 17);
	if (code == -10)
		write(STDERR_FILENO, "Error\nBad color\n", 17);
	if (code == -11)
		write(STDERR_FILENO, "Error\nBad EOL\n", 15);
	exit(code);
}
