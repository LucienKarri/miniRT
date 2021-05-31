#include "../includes/minirt.h"

void	check_open(char *arg, int *fd)
{
	int	i;

	i = 0;
	*fd = open(arg, O_RDONLY);
	if (*fd <= 0)
		error_and_exit(-3);
	while (arg[i] != '.' && arg[i] != '\0')
		i++;
	if (!arg[i])
		error_and_exit(-4);
	if (i < 3 || ft_strcmp(&arg[i], ".rt"))
		error_and_exit(-5);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_all	*all;
	t_sc	*new_sc;
	t_data	img;

	if (argc < 2 || argc > 3)
		error_and_exit(-2);
	check_open(argv[1], &fd);
	new_sc = parsing(fd);
	if (!new_sc)
		error_and_exit(-6);
	close(fd);
	all = all_default(new_sc, &img);
	ray_tracing(all->data, all->sc);
	if (argc == 2)
	{
		all->win = mlx_new_window(all->mlx, all->sc->width, all->sc->hight, "miniRT");
		mlx_put_image_to_window(all->mlx, all->win, all->data->img, 0, 0);
		mlx_key_hook(all->win, keys_control, all);
        mlx_hook(all->win, 17, 1L << 0, close_program, all);
		mlx_loop(all->mlx);
	}
	else if (argc == 3 && !(ft_strcmp(argv[2], "--save")))
		bmp_file(all);
	else
		error_and_exit(-7);
}
