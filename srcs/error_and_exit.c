#include "../includes/minirt.h"

void    error_and_exit(int code)
{
    if (code == -1)
        write(STDERR_FILENO, "Error: Can't allocate memory\n", 30);
    if (code == -2)
        write(STDERR_FILENO, "Error: Wrong number of arguments\n", 34);
    if (code == -3)
        write(STDERR_FILENO, "Error: No such file or directory\n", 34);
    if (code == -4)
        write(STDERR_FILENO, "Error: No extension\n", 21);
    if (code == -5)
        write(STDERR_FILENO, "Error: Invalid extension\n", 26);
    if (code == -6)
        write(STDERR_FILENO, "Error: Invalid scene description\n", 26);
    if (code == -7)
        write(STDERR_FILENO, "Error: Error with ""save""\n", 24);
    exit(code);
}