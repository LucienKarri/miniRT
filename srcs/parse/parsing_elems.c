#include "../../includes/minirt.h"

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
		if (count == 1)
			i += ft_ato_vec(&line[i], &pos);
		if (count == 2)
			i += ft_ato_vec(&line[i], &dir);
		if (count == 3)
			i += ft_ato_float(&line[i], &fov);
	}
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
		if (count == 1)
			i += ft_ato_vec(&line[i], &pos);
		if (count == 2)
			i += ft_ato_float(&line[i], &ratio);
		if (count == 3)
			i += ft_ato_col(&line[i], &color);
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
		if (count == 1)
			i += ft_ato_float(&line[i], &ratio);
		if (count == 2)
			i += ft_ato_col(&line[i], &color);
	}
	if (ratio < 0 || ratio > 1)
		error_and_exit(-9);
	ambient = a_default(ratio, color);
	scene->a = ambient;
	return (0);
}
