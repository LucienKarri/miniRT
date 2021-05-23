#include "../includes/minirt.h"

int		choise_element(t_sc *sc, char *line)
{
	if (line[0] != '\0')
	{
//		printf("test3\n");
		if (line[0] == 'R')
		{
//			printf("test1\n");
			return (parsing_resolution(sc, line));
		}
		else if (line[0] == 'A')
		{
//			printf("test2\n");
			return (parsing_ambient_light(sc, line));
		}
		else if (line[0] == 'c')
			return (parsing_cam(sc, line));
		else if (line[0] == 'l')
			return (parsing_light(sc, line));
		else if (line[0] == 's' && line[1] == 'p')
		{
			printf("test\n");
			return (parsing_sphere(sc, line));
		}
//		else if (line[0] == 't' && line[1] == 'r')
//			return ();
//		else if (line[0] == 'p' && line[1] == 'l')
//			return ();
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

	new_scene = empty_scene(0);
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		if ((rd = choise_element(new_scene, line)) < 0)
			return (NULL);
	//	printf("%d, %d\n", new_scene->width, new_scene->hight);
	//	printf("%f, %d\n", new_scene->a->ratio, new_scene->a->color);
		free(line);
	}
	if (rd < 0 || (rd = choise_element(new_scene, line)) < 0)
		return (NULL);
	return (new_scene);
}