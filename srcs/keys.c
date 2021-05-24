#include "../includes/minirt.h"

int		keys_control(int keycode, t_all *all)
{
//	(void)all;
	if (keycode == 65363)
		all->sc->cam = all->sc->cam->next;
	if (keycode == 65307)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	ray_tracing(all->data, all->sc);
	mlx_put_image_to_window(all->mlx, all->win, all->data->img, 0, 0);
//	printf("%i\n", keycode);
	return (0);
}