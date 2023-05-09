/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** init.c file.
*/

#include "core.h"

druid_t *init_druid(unsigned int nb_refills)
{
    druid_t *druid = malloc(sizeof(druid_t));

    if (druid == NULL) {
        return (NULL);
    }
    druid->fill_requested = false;
    druid->remaining_fills = nb_refills;
    druid->villagers_fights_nb = 0;
    druid->thread = 0;
    return (druid);
}
