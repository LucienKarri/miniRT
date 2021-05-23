#include "../includes/minirt.h"

int	parsing_sphere(t_sc *scene, char *line)
{
	int		i = 2;
	int		count = 0;
	int 	color;
	float	radius;
	t_vec	*center;

	while (count <= 3)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			count++;
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

int parsing_resolution(t_sc *scene, char *line)
{
	int		i = 1;
	int		count = 0;

	while (count <= 2)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if (line[i] <= '0' && line[i] >= '9')
			return (-1);
		else
		{
			count++;
			if (count == 1)
				i += ft_atoi(&line[i], &scene->width);
			if (count == 2)
				i += ft_atoi(&line[i], &scene->hight);
		}
	}
	return (0);
}

int parsing_cam(t_sc *scene, char *line)
{
	int i = 1;
	int count = 0;
	t_vec	*pos;
	t_vec	*dir;
	float	fov;
	while (count <= 3)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			count++;
			if (count == 1)
				i += ft_ato_vec(&line[i], &pos);
			if (count == 2)
				i += ft_ato_vec(&line[i], &dir);
			if (count == 3)
				i += ft_ato_float(&line[i], &fov);
		}
	}
	cam_list(&scene->cam, pos, dir, fov);
	return (0);
}

int parsing_light(t_sc *scene, char *line)
{
	int		i = 1;
	int		count = 0;
	int 	color;
	float	ratio;
	t_vec	*pos;

	while (count <= 3)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			count++;
			if (count == 1)
				i += ft_ato_vec(&line[i], &pos);
			if (count == 2)
				i += ft_ato_float(&line[i], &ratio);
			if (count == 3)
				i += ft_ato_col(&line[i], &color);
		}
	}
	l_list(&scene->l, pos, ratio, color);
	return (0);
}

int parsing_ambient_light(t_sc *scene, char *line)
{
	int		i = 1;
	int		count = 0;
	int 	color;
	float	ratio;
	t_a		*ambient;
	while (count <= 2)
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && line[i] <= '0' && line[i] >= '9'))
			return (-1);
		else
		{
			count++;
			if (count == 1)
				i += ft_ato_float(&line[i], &ratio);
			if (count == 2)
				i += ft_ato_col(&line[i], &color);
		}
	}
	ambient = a_default(ratio, color);
	scene->a = ambient;
	return (0);
}