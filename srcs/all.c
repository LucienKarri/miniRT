#include "../includes/minirt.h"

t_all	*all_default(void *mlx, t_sc *sc, t_data *data)
{
	t_all	*new;

	new = malloc(sizeof(t_all));
	new->data = data;
	new->sc = sc;
	new->mlx = mlx;
	new->win = NULL;
	return (new);
}
