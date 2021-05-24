#include "../includes/minirt.h"

int		main(int argc, char **argv)
{
	int		fd;
	void	*mlx;
	void	*window;
	t_data	img;
	t_all	*new_all;
	t_sc	*new_sc;

	if (argc ==2 || argc == 3)
	{
		mlx = mlx_init();
		fd = open(argv[1], O_RDONLY);
		new_sc = parsing(fd);
		close(fd);
		img.img = mlx_new_image(mlx, new_sc->width, new_sc->hight);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img
		.line_length, &img.endian);
		new_all = all_default(mlx, new_sc, &img);
		ray_tracing(new_all->data, new_all->sc);
		if (argc == 2)
		{
			window = mlx_new_window(mlx, new_sc->width, new_sc->hight, "GOLOD");
			new_all->win = window;
			mlx_put_image_to_window(new_all->mlx, new_all->win, new_all->data->img, 0,0);
			mlx_key_hook(window, keys_control, new_all);
			printf("READY!\n");
			mlx_loop(mlx);
		}
		else
		{
			bmp_file(new_all);
			exit(0);
		}
		return (0);
	}
	return (-1);
}