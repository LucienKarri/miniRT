#include "../includes/minirt.h"

int		ft_intersection(t_sc *scene, t_vec *ray)
{
	t_sp	*close_sp = NULL;
	float	c_sp = 100000;
	t_tr	*close_tr = NULL;
	float	c_tr = 100000;
	int 	close_color = 0;
	float	tmp = 100000;
	t_vec	*p;
	t_vec	*nrmd;

	close_sp = closing_sp(scene->cam->pos, ray, scene, 1, 100000);
	if (close_sp != NULL)
//		printf("%f\n", close_sp->distance);
	close_tr = closing_tr(scene->cam->pos, ray, scene);
	if (close_tr == NULL && close_sp == NULL)
		return (0);
	if (close_tr != NULL)
		c_tr = close_tr->distance;
	if (close_sp != NULL)
		c_sp = close_sp->distance;
	if (c_sp < c_tr)
		tmp = c_sp;
	else if (c_sp > c_tr)
		tmp = c_tr;
	p = vec_sum(scene->cam->pos, vec_multiplication(ray, tmp));
	if (c_sp < c_tr)
	{
		nrmd = vec_subtract(p, close_sp->center);
		vec_normalize(nrmd);
		close_color = close_sp->color;
	}
	else if (c_tr < c_sp)
	{
		nrmd = vec_cross(vec_subtract(close_tr->p2, close_tr->p1),
				   vec_subtract(close_tr->p3, close_tr->p1));
		close_color = close_tr->color;
	}
	close_color = lightning(p, nrmd, scene, close_color);
	return (close_color);
}

void	ray_tracing(void *mlx, void *window, t_sc *sc)
{
	float		mlx_x;
	float		mlx_y = 0;
	float		resolution_x;
	float		resolution_y;
	float		ray_x;
	float		ray_y;
	t_vec		*ray;
	t_screen	*scr;
	int			color;

	scr = screen_default(sc->width, sc->hight, sc->cam->fov);
	resolution_y = (sc->hight / 2);
	while (resolution_y >= (sc->hight / 2) * (-1))
	{
		ray_y = resolution_y * scr->screen_y;
		resolution_x = (sc->width / 2) * (-1);
		mlx_x = 0;
		while (resolution_x <= sc->width / 2)
		{
			ray_x = resolution_x * scr->screen_x;
			ray = vec_default(ray_x, ray_y, 1);
//			printf("%f, %f, %f\n", ray->x, ray->y, ray->z);
			vec_normalize(ray);
			ray = look_at(sc->cam, ray);
//			rotation(ray, sc->cam->direction);
			vec_normalize(ray);
//			printf("%f, %f, %f\n\n", ray->x, ray->y, ray->z);
//			rotation(ray, sc->cam->direction);
//			vec_normalize(ray);
			color = ft_intersection(sc, ray);
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free(ray);
			resolution_x++;
			mlx_x++;
		}
		resolution_y--;
		mlx_y++;
	}
}