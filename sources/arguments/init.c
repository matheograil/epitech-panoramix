/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** init.c file.
*/

#include "core.h"

arguments_t *init_arguments(char **av)
{
    arguments_t *args = malloc(sizeof(arguments_t));

    if (args == NULL) {
        return (NULL);
    }
    args->nb_villagers = (unsigned int)strtol(av[1], NULL, 10);
    args->pot_size = (unsigned int)strtol(av[2], NULL, 10);
    args->nb_fights = (unsigned int)strtol(av[3], NULL, 10);
    args->nb_refills = (unsigned int)strtol(av[4], NULL, 10);
    return (args);
}
