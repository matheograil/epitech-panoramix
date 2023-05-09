/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** init_structures.c file.
*/

#include "core.h"

parameters_t *init_structures(char **av)
{
    arguments_t *args = NULL;
    parameters_t *params = NULL;
    villager_t *villagers = NULL;
    pot_t *pot = NULL;
    druid_t *druid = NULL;

    if ((args = init_arguments(av)) == NULL)
        return (NULL);
    villagers = init_villagers(args->nb_villagers, args->nb_fights);
    if (villagers == NULL)
        return (free_sub_structures(args, NULL, NULL, NULL));
    if ((pot = init_pot(args->pot_size)) == NULL)
        return (free_sub_structures(args, villagers, NULL, NULL));
    if ((druid = init_druid(args->nb_refills)) == NULL)
        return (free_sub_structures(args, villagers, pot, NULL));
    if ((params = init_parameters(villagers, args, pot, druid)) == NULL)
        return (free_sub_structures(args, villagers, pot, druid));
    return (params);
}

void *free_sub_structures(arguments_t *args, villager_t *villagers, pot_t *pot,
    druid_t *druid)
{
    my_free(args);
    free_villagers(villagers);
    my_free(pot);
    my_free(druid);
    return (NULL);
}
