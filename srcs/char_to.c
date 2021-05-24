#include "../includes/minirt.h"

int	ft_atoi(char *str, int *number)
{
	int		i;
	int		znak;
	long	num;
	long	output;

	i = 0;
	output = 0;
	znak = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		znak = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = str[i] - '0';
		output = output * 10 + num;
		i++;
	}
	*number = (output * znak);
	if (i == 0)
		return (-1);
	return (i);
}

int	ft_ato_float(char *str, float *number)
{
	int		i;
	int		num;
	float	zero_point;

	if ((i = ft_atoi(str, &num)) < 0)
		return (-1);
	*number = num;
	if (str[i] == '.')
		i++;
	zero_point = 0.1;
	if (num < 0)
		zero_point *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*number = zero_point * (str[i] - '0') + *number;
		zero_point = zero_point * 0.1;
		i++;
	}
	return (i);
}

int	ft_ato_vec(char *str, t_vec **vec)
{
	int		i;
	int		xyz;
	int		writed;
	float	v[3];

	i = 0;
	xyz = 0;
	while (xyz < 3)
	{
		if ((writed = ft_ato_float(&str[i], &v[xyz])) < 0)
			return (-1);
		i = i + writed;
		if (xyz < 2 && str[i] != ',')
			return (-1);
		else if (xyz < 2 && str[i] == ',')
			i++;
		xyz++;
	}
	if (!(*vec = vec_default(v[0], v[1], v[2])))
		return (-1);
	return (i);
}

int	ft_ato_col(char *str, int *color)
{
	int	i;
	int	writen;
	int	canal;
	int	rgb[3];

	i = 0;
	canal = 0;
	writen = 0;
	while (canal < 3)
	{
		if ((writen = ft_atoi(&str[i], &rgb[canal])) < 0)
			return (-1);
		if (rgb[canal] < 0 || rgb[canal] > 255)
			return (-1);
		i = writen + i;
		if (canal < 2 && str[i] != ',')
			return (-1);
		else if (canal < 2 && str[i] == ',')
			i++;
		canal++;
	}
	*color = creat_color(rgb[0], rgb[1], rgb[2]);
	return (i);
}
