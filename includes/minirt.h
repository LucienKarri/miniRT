#ifndef MINIRT_H
# define MINIRT_H

/*standard libraries*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>

/*other libraries*/
#include "../mlx_linux/mlx.h"
#include "data.h"
#include "color.h"
#include "vector.h"
#include "camera.h"
#include "sphere.h"
#include "triangle.h"
#include "plane.h"
#include "square.h"
#include "ambient_lightning.h"
#include "light.h"
#include "scene.h"
#include "all.h"
#include "view_screen.h"
#include "error_and_exit.h"
#include "../srcs/get_next_line/get_next_line.h"

/*ray tracing*/
void	ray_tracing(t_data *data, t_sc *sc);

int		lightning(t_vec *p, t_vec *n, t_sc *sc, int color);

t_sp	*closing_sp(t_vec *pos, t_vec *ray, t_sc *sc, float min, float max);
t_tr	*closing_tr(t_vec *pos, t_vec *ray, t_sc *sc);
t_pl	*closing_pl(t_vec *pos, t_vec *ray, t_sc *sc);

int     ft_ato_col(char *str, int *color);
int     ft_ato_vec(char *str, t_vec **vec);
int     ft_ato_float(char *str, float *number);
int     ft_atoi(char *str, int *number);

int		keys_control(int keycode, t_all *all);
t_sc	*parsing(int fd);
int		choise_element(t_sc *sc, char *line);
int		parsing_sphere(t_sc *scene, char *line);
int     parsing_resolution(t_sc *scene, char *line);
int     parsing_cam(t_sc *scene, char *line);
int     parsing_light(t_sc *scene, char *line);
int     parsing_ambient_light(t_sc *scene, char *line);
int     parsing_triangle(t_sc *scene, char *line);
int     parsing_plane(t_sc *scene, char *line);

void    bmp_file(t_all *all);
void    bmp_info(t_all *all, int fd);
void    bmp_header(t_all *all, int fd);

int ft_strcmp(const char *str1, const char *str2);

#endif