NAME			=	minirt

INCLUDES		=	./includes/

SRCS			=	srcs/vector.c \
					srcs/camera.c \
					srcs/scene.c \
					srcs/sphere.c \
					srcs/ray_trace.c \
					srcs/main.c \
					srcs/screen.c \
					srcs/sp_crossing.c \
					srcs/triangle.c \
					srcs/tr_crossing.c \
					srcs/pl_intersection.c \
					srcs/plane.c \
					srcs/light.c \
					srcs/lightning.c \
					srcs/ambient_lightning.c \
					srcs/color.c \
					srcs/close_obj.c \
					srcs/rotation.c \

OBJS			=	${SRCS:.c=.o}

MLX				=	minilibx-linux/*.a

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

LFLAGS			=	-L.. -lmlx -lXext -lX11 -lm -lbsd

RM				=	rm -rf

.c.o:
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
						${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} ${MLX} ${LFLAGS} -o ${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re