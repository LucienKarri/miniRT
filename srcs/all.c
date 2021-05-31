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
    mlx_get_screen_size(new->mlx, &new->x, &new->y);
    if (new->sc->width > new->x)
        new->sc->width = new->x;
    if (new->sc->hight > new->y)
    {
        new->sc->hight = new->y;
    }
	new->win = NULL;
	img->img = mlx_new_image(new->mlx, new->sc->width, new->sc->hight);
	img->addr = mlx_get_data_addr(img->img, &img->b_p_p,
			&img->line_len, &img->endian);
	new->data = img;
	return (new);
}
