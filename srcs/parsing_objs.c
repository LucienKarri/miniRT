#include "../includes/minirt.h"

int	parsing_sphere(t_sc **scene, char *line)
{
	int		i = 2;
	int		count = 0;
	int 	color;
	float	radius;
	t_vec	*center;

	while (count <= 3)
	{
		while (l[i] == ' ' || (l[i] >= 9 && l[i] <= 13))
			i++;
		if ((l[i] != '-' && l[i] <= '0' && l[i] >= '9'))
			return (-1);
		else
		{
			count++;
			if (count == 1)
				i = ft_ato_vec(&line[i], &center);
			if (count == 2)
				i = ft_ato_float(&line[i], &radius);
			if (count == 3)
				i = ft_ato_col(&line[i], &color);
		}
	}
	sp_list(&(*scene)->sp, center, radius, color);

}