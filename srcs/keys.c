#include "../includes/minirt.h"

int	keys_control(int keycode, t_all *all)
{
    t_cam   *tmp;

    tmp = all->sc->cam;
	if (keycode == 65363 && all->sc->cam != NULL)
    {
        all->sc->cam = all->sc->cam->next;
        free(tmp->direction);
        free(tmp->pos);
        free(tmp);
    }
	if (keycode == 65307 || all->sc->cam == NULL)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	ray_tracing(all->data, all->sc);
	mlx_put_image_to_window(all->mlx, all->win, all->data->img, 0, 0);
	return (0);
}

int	close_program(t_all *all)
{
	mlx_destroy_window(all->mlx, all->win);
	exit(0);
	return (0);
}
