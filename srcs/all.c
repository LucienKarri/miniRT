#include "../includes/minirt.h"

t_all	*all_default(t_sc *sc, t_data *img)
{
	t_all	*new;

	new = malloc(sizeof(t_all));
	if (!new)
		error_and_exit(-1);
	new->data = NULL;
	new->sc = sc;
	new->mlx = mlx_init();
	new->win = NULL;
	img->img = mlx_new_image(new->mlx, new->sc->width, new->sc->hight);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	new->data = img;
	return (new);
}
