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
#include "vector.h"
#include "camera.h"
#include "sphere.h"
#include "triangle.h"
#include "plane.h"
#include "cylinder.h"
#include "scene.h"
#include "view_screen.h"

/*ray tracing*/
void	ray_tracing(void *mlx, void *window, t_sc *sc);

#endif