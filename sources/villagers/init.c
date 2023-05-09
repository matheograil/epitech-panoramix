/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** init.c file.
*/

#include "core.h"

villager_t *init_villagers(unsigned int nb_villagers, unsigned int nb_fights)
{
    villager_t *villagers = malloc(sizeof(villager_t));

    if (villagers == NULL) {
        return (NULL);
    }
    villagers->id = -1;
    villagers->remaining_fights = 0;
    villagers->next = NULL;
    villagers->thread = 0;
    for (unsigned int i = 0; i <= nb_villagers; i++) {
        add_villager(villagers, nb_fights);
    }
    return (villagers);
}
