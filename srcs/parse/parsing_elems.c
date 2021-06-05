#include "../../includes/minirt.h"

int	parsing_resolution(t_sc *scene, char *line)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	if (scene->width > 0 || scene->hight > 0)
		error_and_exit(-6);
	while (++count <= 2 && line[i])
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if (line[i] < '0' || line[i] > '9')
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
	check_eol(&line[i], 3, count);
	return (0);
}

int	parsing_cam(t_sc *scene, char *line)
{
	int		k[2];
	t_vec	*v[2];
	double	fov;

	k[0] = 1;
	k[1] = 0;
	while (++k[1] <= 3 && line[k[0]])
	{
		while (line[k[0]] == ' ' || (line[k[0]] >= 9 && line[k[0]] <= 13))
			k[0]++;
		if ((line[k[0]] != '-' && (line[k[0]] < '0' || line[k[0]] > '9')))
			return (-1);
		if (k[1] == 1)
			k[0] += ft_ato_vec(&line[k[0]], &v[0]);
		if (k[1] == 2)
			k[0] += ft_ato_vec(&line[k[0]], &v[1]);
		if (k[1] == 3)
			k[0] += ft_ato_float(&line[k[0]], &fov);
	}
	if (v[1]->x < -1 || v[1]->x > 1 || v[1]->y < -1 || v[1]->y > 1
		|| v[1]->z < -1 || v[1]->z > 1 || fov < 0 || fov > 180)
		error_and_exit(-9);
	check_eol(&line[k[0]], 4, k[1]);
	cam_list(&scene->cam, v[0], v[1], fov);
	return (0);
}

int	parsing_light(t_sc *scene, char *line)
{
	int		color;
	int		k[3];
	double	ratio;
	t_vec	*pos;

	k[0] = 1;
	k[1] = 0;
	while (++k[1] <= 3 && line[k[0]])
	{
		while (line[k[0]] == ' ' || (line[k[0]] >= 9 && line[k[0]] <= 13))
			k[0]++;
		if ((line[k[0]] != '-' && (line[k[0]] < '0' || line[k[0]] > '9')))
			return (-1);
		if (k[1] == 1)
			k[0] += ft_ato_vec(&line[k[0]], &pos);
		if (k[1] == 2)
			k[0] += ft_ato_float(&line[k[0]], &ratio);
		if (k[1] == 3)
			k[0] += ft_ato_col(&line[k[0]], &color);
	}
	if (ratio < 0 || ratio > 1)
		error_and_exit(-9);
	check_eol(&line[k[0]], 4, k[1]);
	l_list(&scene->l, pos, ratio, color);
	return (0);
}

int	parsing_ambient_light(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	double	ratio;

	i = 1;
	count = 0;
	if (scene->a != NULL)
		error_and_exit(-6);
	while (++count <= 2 && line[i])
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && (line[i] < '0' || line[i] > '9')))
			return (-1);
		if (count == 1)
			i += ft_ato_float(&line[i], &ratio);
		if (count == 2)
			i += ft_ato_col(&line[i], &color);
	}
	if (ratio < 0 || ratio > 1)
		error_and_exit(-9);
	check_eol(&line[i], 3, count);
	scene->a = a_default(ratio, color);
	return (0);
}
