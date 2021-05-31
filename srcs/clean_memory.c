#include "../includes/minirt.h"

void    free_vector(t_all *all)
{
    while (all->sc->sp)
    {
        free(all->sc->sp->center);
        all->sc->sp = all->sc->sp->next;
    }
    while (all->sc->pl)
    {
        free(all->sc->pl->crd);
        free(all->sc->pl->nrmd);
        all->sc->pl = all->sc->pl->next;
    }
    while (all->sc->sq)
    {
        free(all->sc->sq->center);
        free(all->sc->sq->nrmd);
        all->sc->sq = all->sc->sq->next;
    }
    while (all->sc->tr)
    {
        free(all->sc->tr->p1);
        free(all->sc->tr->p2);
    }
    
    
}

void    free_scene(t_sc *scene)
{
    while (scene->tr)
    {
        free(scene->tr);
        scene->tr = scene->tr->next;
    }
    while (scene->sp)
    {
        free(scene->sp);
        scene->sp = scene->sp->next;
    }
}

void    free_memory(t_all *all)
{

}