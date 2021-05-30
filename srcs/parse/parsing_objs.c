#include "../includes/minirt.h"

int	parsing_sphere(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	double	radius;
	t_vec	*center;

	i = 2;
	count = 0;
	while (++count <= 3)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			if (count == 1)
				i += ft_ato_vec(&line[i], &center);
			if (count == 2)
				i += ft_ato_float(&line[i], &radius);
			if (count == 3)
				i += ft_ato_col(&line[i], &color);
		}
	}
	sp_list(&scene->sp, center, radius, color);
	return (0);
}

int	parsing_resolution(t_sc *scene, char *line)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (++count <= 2)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if (line[i] <= '0' && line[i] >= '9')
			return (-1);
		else
		{
			if (count == 1)
				i += ft_atoi(&line[i], &scene->width);
			if (count == 2)
				i += ft_atoi(&line[i], &scene->hight);
		}
	}
	if (scene->width <= 0 || scene->hight <= 0)
		error_and_exit(-8);
	return (0);
}

int	parsing_cam(t_sc *scene, char *line)
{
	int		i;
	int		count;
	t_vec	*pos;
	t_vec	*dir;
	double	fov;

	i = 1;
	count = 0;
	while (++count <= 3)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			if (count == 1)
				i += ft_ato_vec(&line[i], &pos);
			if (count == 2)
				i += ft_ato_vec(&line[i], &dir);
			if (count == 3)
				i += ft_ato_float(&line[i], &fov);
		}
	}
	if (dir->x < -1 || dir->x > 1 || dir->y < -1 || dir->y > 1 || dir->z < -1 || dir->z > 1)
		error_and_exit(-9);
	cam_list(&scene->cam, pos, dir, fov);
	return (0);
}

int	parsing_light(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	double	ratio;
	t_vec	*pos;

	i = 1;
	count = 0;
	while (++count <= 3)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			if (count == 1)
				i += ft_ato_vec(&line[i], &pos);
			if (count == 2)
				i += ft_ato_float(&line[i], &ratio);
			if (count == 3)
				i += ft_ato_col(&line[i], &color);
		}
	}
	if (ratio < 0 || ratio > 1)
		error_and_exit(-9);
	l_list(&scene->l, pos, ratio, color);
	return (0);
}

int	parsing_ambient_light(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	double	ratio;
	t_a		*ambient;

	i = 1;
	count = 0;
	while (++count <= 2)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			if (count == 1)
				i += ft_ato_float(&line[i], &ratio);
			if (count == 2)
				i += ft_ato_col(&line[i], &color);
		}
	}
	if (ratio < 0 || ratio > 1)
		error_and_exit(-9);
	ambient = a_default(ratio, color);
	scene->a = ambient;
	return (0);
}

int	parsing_triangle(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	t_vec	*p[3];

	i = 2;
	count = 0;
	while (++count <= 4)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			if (count == 1)
				i += ft_ato_vec(&line[i], &p[0]);
			if (count == 2)
				i += ft_ato_vec(&line[i], &p[1]);
			if (count == 3)
				i += ft_ato_vec(&line[i], &p[2]);
			if (count == 4)
				i += ft_ato_col(&line[i], &color);
		}
	}
	tr_list(&scene->tr, p, color);
	return (0);
}

int	parsing_plane(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	t_vec	*pos;
	t_vec	*nrmd;

	i = 2;
	count = 0;
	while (++count <= 3)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			if (count == 1)
				i += ft_ato_vec(&line[i], &pos);
			if (count == 2)
				i += ft_ato_vec(&line[i], &nrmd);
			if (count == 3)
				i += ft_ato_col(&line[i], &color);
		}
	}
	if (nrmd->x < -1 || nrmd->x > 1 || nrmd->y < -1 || nrmd->y > 1 || nrmd->z < -1 || nrmd->z > 1)
		error_and_exit(-9);
	pl_list(&scene->pl, pos, nrmd, color);
	return (0);
}

int	parsing_square(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	double	side;
	t_vec	*pos;
	t_vec	*nrmd;

	i = 2;
	count = 0;
	while (++count <= 4)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			if (count == 1)
				i += ft_ato_vec(&line[i], &pos);
			if (count == 2)
				i += ft_ato_vec(&line[i], &nrmd);
			if (count == 3)
				i += ft_ato_float(&line[i], &side);
			if (count == 4)
				i += ft_ato_col(&line[i], &color);
		}
	}
	if (nrmd->x < -1 || nrmd->x > 1 || nrmd->y < -1 || nrmd->y > 1 || nrmd->z < -1 || nrmd->z > 1)
		error_and_exit(-9);
	sq_list(&scene->sq, pos, nrmd, side, color);
	return (0);
}

int	parsing_cylinder(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	t_vec	*pos;
	t_vec	*nrmd;
	double	diametr;
	double	height;

	i = 2;
	count = 0;
	while (++count <= 5)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			if (count == 1)
				i += ft_ato_vec(&line[i], &pos);
			if (count == 2)
				i += ft_ato_vec(&line[i], &nrmd);
			if (count == 3)
				i += ft_ato_float(&line[i], &diametr);
			if (count == 4)
				i += ft_ato_float(&line[i], &height);
			if (count == 5)
				i += ft_ato_col(&line[i], &color);
		}
	}
	if (nrmd->x < -1 || nrmd->x > 1 || nrmd->y < -1 || nrmd->y > 1 || nrmd->z < -1 || nrmd->z > 1)
		error_and_exit(-9);
	cy_list(&scene->cy, pos, nrmd, diametr, height, color);
	return (0);
}
