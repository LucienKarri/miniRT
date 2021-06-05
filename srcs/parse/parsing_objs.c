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
	while (++count <= 3 && line[i])
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && (line[i] < '0' || line[i] > '9')))
			return (-1);
		if (count == 1)
			i += ft_ato_vec(&line[i], &center);
		if (count == 2)
			i += ft_ato_float(&line[i], &radius);
		if (count == 3)
			i += ft_ato_col(&line[i], &color);
	}
	check_eol(&line[i], 4, count);
	sp_list(&scene->sp, center, radius, color);
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
	while (++count <= 4 && line[i])
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && (line[i] < '0' || line[i] > '9')))
			return (-1);
		if (count == 1)
			i += ft_ato_vec(&line[i], &p[0]);
		if (count == 2)
			i += ft_ato_vec(&line[i], &p[1]);
		if (count == 3)
			i += ft_ato_vec(&line[i], &p[2]);
		if (count == 4)
			i += ft_ato_col(&line[i], &color);
	}
	check_eol(&line[i], 5, count);
	tr_list(&scene->tr, p, color);
	return (0);
}

int	parsing_plane(t_sc *scene, char *line)
{
	int		i;
	int		count;
	int		color;
	t_vec	*v[2];

	i = 2;
	count = 0;
	while (++count <= 3 && line[i])
	{
		while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		if ((line[i] != '-' && (line[i] < '0' || line[i] > '9')))
			return (-1);
		if (count == 1)
			i += ft_ato_vec(&line[i], &v[0]);
		if (count == 2)
			i += ft_ato_vec(&line[i], &v[1]);
		if (count == 3)
			i += ft_ato_col(&line[i], &color);
	}
	check_elem(v[1]);
	check_eol(&line[i], 4, count);
	pl_list(&scene->pl, v[0], v[1], color);
	return (0);
}

int	parsing_square(t_sc *scene, char *line)
{
	int		k[3];
	double	side;
	t_vec	*v[2];

	k[0] = 2;
	k[1] = 0;
	while (++k[1] <= 4 && line[k[0]])
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
			k[0] += ft_ato_float(&line[k[0]], &side);
		if (k[1] == 4)
			k[0] += ft_ato_col(&line[k[0]], &k[2]);
	}
	check_elem(v[1]);
	check_eol(&line[k[0]], 5, k[1]);
	sq_list(&scene->sq, v, side, k[2]);
	return (0);
}

int	parsing_cylinder(t_sc *scene, char *line)
{
	int		k[3];
	t_vec	*v[2];
	double	t[2];

	k[0] = 2;
	k[1] = 0;
	while (++k[1] <= 5 && line[k[0]])
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
			k[0] += ft_ato_float(&line[k[0]], &t[0]);
		if (k[1] == 4)
			k[0] += ft_ato_float(&line[k[0]], &t[1]);
		if (k[1] == 5)
			k[0] += ft_ato_col(&line[k[0]], &k[2]);
	}
	check_eol(&line[k[0]], 6, k[1]);
	return (cy_list(&scene->cy, v, t, k[2]));
}
