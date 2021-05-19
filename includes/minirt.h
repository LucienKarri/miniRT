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
#include "mlx.h"
#include "data.h"
#include "keys.h"
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
#include "view_screen.h"

/*ray tracing*/
void	ray_tracing(t_data *data, t_sc *sc);

int		lightning(t_vec *p, t_vec *n, t_sc *sc, int color);

t_sp	*closing_sp(t_vec *pos, t_vec *ray, t_sc *sc, float min, float max);
t_tr	*closing_tr(t_vec *pos, t_vec *ray, t_sc *sc);
t_pl	*closing_pl(t_vec *pos, t_vec *ray, t_sc *sc);

int ft_ato_col(char *str, int *color);
int ft_ato_vec(char *str, t_vec **vec);
int	ft_ato_float(char *str, float *number);
int	ft_atoi(char *str, int *number);

void	debug_sp(t_sp *sp);
#endif