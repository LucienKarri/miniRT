#include "../../includes/minirt.h"

t_cy    *cy_default(t_vec *origin, t_vec *nrmd, double diametr, double height, int color)
{
    t_cy    *new_cy;

    new_cy = malloc(sizeof(t_cy));
    if (!new_cy)
        error_and_exit(-1);
    new_cy->origin = origin;
    new_cy->nrmd = nrmd;
    new_cy->diametr = diametr / 2;
    new_cy->height = height;
    new_cy->color = color;
    new_cy->distance1 = 0;
    new_cy->distance2 = 0;
    new_cy->distance = 0;
    new_cy->li = NULL;
    new_cy->next = NULL;
    return (new_cy);
}

void    cy_list(t_cy **cy_list, t_vec *origin, t_vec *nrmd, double diametr, double height, int color)
{
    t_cy    *new_cy;

    new_cy = cy_default(origin, nrmd, diametr, height, color);
    new_cy->next = *cy_list;
    *cy_list = new_cy;
}