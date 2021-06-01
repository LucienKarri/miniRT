#include "../includes/minirt.h"

int	choise_element(t_sc *sc, char *line)
{
	if (line[0] != '\0')
	{
		if (line[0] == 'R')
			return (parsing_resolution(sc, line));
		else if (line[0] == 'A')
			return (parsing_ambient_light(sc, line));
		else if (line[0] == 'c' && line[1] == 'y')
			return (parsing_cylinder(sc, line));
		else if (line[0] == 'c')
			return (parsing_cam(sc, line));
		else if (line[0] == 'l')
			return (parsing_light(sc, line));
		else if (line[0] == 's' && line[1] == 'p')
			return (parsing_sphere(sc, line));
		else if (line[0] == 't' && line[1] == 'r')
			return (parsing_triangle(sc, line));
		else if (line[0] == 'p' && line[1] == 'l')
			return (parsing_plane(sc, line));
		else if (line[0] == 's' && line[1] == 'q')
			return (parsing_square(sc, line));
		else
			return (-1);
	}
	return (0);
}

t_sc	*parsing(int fd)
{
	t_sc	*new_scene;
	char	*line;
	int		rd;

	new_scene = empty_scene();
	rd = get_next_line(fd, &line);
	while (rd > 0)
	{
		rd = choise_element(new_scene, line);
		if (rd < 0)
			return (NULL);
		free(line);
		rd = get_next_line(fd, &line);
	}
	rd = choise_element(new_scene, line);
	free(line);
	if (rd < 0)
		return (NULL);
	return (new_scene);
}
